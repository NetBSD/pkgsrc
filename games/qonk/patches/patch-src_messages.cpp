$NetBSD: patch-src_messages.cpp,v 1.1 2016/12/31 10:01:11 dholland Exp $

Fix display color of (some) messages.

--- src/messages.cpp.orig	2007-09-14 05:43:03.000000000 +0000
+++ src/messages.cpp
@@ -21,8 +21,8 @@ Message::Message( Uint32 time, string me
 Message::Message( Uint32 time, string message, Uint32 displayTime, Uint32 color ) {
   this->message = string( "[" ) + Timer::getTimeMMSS(time) + "] " + message;
   this->displayTime = displayTime;
-  this->r = getGreen( color );
-  this->g = getRed( color );
+  this->r = getRed( color );
+  this->g = getGreen( color );
   this->b = getBlue( color );
 }
 
@@ -37,8 +37,8 @@ Message::Message( Uint32 time, string me
 Message::Message( Uint32 time, string message, Uint32 color ) {
   this->message = string( "[" ) + Timer::getTimeMMSS(time) + "] " + message;
   this->displayTime = 10000;
-  this->r = getGreen( color );
-  this->g = getRed( color );
+  this->r = getRed( color );
+  this->g = getGreen( color );
   this->b = getBlue( color );
 }
 
