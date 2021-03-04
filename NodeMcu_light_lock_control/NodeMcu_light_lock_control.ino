

//It was to get the request from web
//and on and off thE LIGHT AS PER
//RECIEVED REQUEST...

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "SAYAN's WIFI";
const char* password = "ItsSayanPramanik134";
 
void setup () {
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting..");
  }
}
 
void loop() {
 
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
  //  int a = analogRead(A0);
    String link =  "http://sayan75.000webhostapp.com/dump";
   // String data = String(a, DEC);
    http.begin(link);
    Serial.println(link);

    int httpCode = http.GET();
    //response code

    String payload = "";
    // this is variable to receive response
    
 
    if (httpCode > 0) {
      
      // start of fetching get process
      payload = http.getString();
      Serial.println(payload);
      // print the response
      if(payload=="yes"){
    digitalWrite(2,0);}
    else
    digitalWrite(2,1);

    }
    else
      Serial.println(httpCode);
    http.end();
    // end of fetching get process
  }
  delay(5500);
}
