#include <ESP8266WiFi.h>
#include <FirebaseArduino.h> 
#include <ArduinoJson.h>
#define led D6
#define FIREBASE_HOST "ujjwal-iot-whquqo.firebaseio.com"
#define FIREBASE_AUTH "kH13k75ZCED9uZ56HvXzd3x21GtaxNrrRHZOBan4"
#define WIFI_SSID "ujjwal"
#define WIFI_PASSWORD "ujjwal@123"
String status;
void setup() {
Serial.begin(9600);
pinMode(led, OUTPUT);
// connect to wifi.
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);
}
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
void loop() {
// get value
status = Firebase.getString("ujjwal-iot-whquqo/ledon");
if(status=="1"){
digitalWrite(led,HIGH);
Serial.println("LED ON");
return;
}
else {
Serial.println("LED OFF");
digitalWrite(led,LOW);  
return;
}
}
