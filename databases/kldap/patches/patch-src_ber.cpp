$NetBSD: patch-src_ber.cpp,v 1.1 2020/02/18 16:49:13 joerg Exp $

--- src/ber.cpp.orig	2020-01-14 16:17:11.814803692 +0000
+++ src/ber.cpp
@@ -124,7 +124,7 @@ QByteArray Ber::flatten() const
     return ret;
 }
 
-int Ber::printf(QString format, ...)
+int Ber::printf(const char *format, ...)
 {
     char fmt[2];
     va_list args;
@@ -132,8 +132,8 @@ int Ber::printf(QString format, ...)
     fmt[1] = '\0';
 
     int i = 0, ret = 0;
-    while (i < format.length()) {
-        fmt[0] = format[i].toLatin1();
+    while (format[i]) {
+        fmt[0] = format[i];
         i++;
         switch (fmt[0]) {
         case 'b':
@@ -229,7 +229,7 @@ int Ber::printf(QString format, ...)
     return ret;
 }
 
-int Ber::scanf(QString format, ...)
+int Ber::scanf(const char *format, ...)
 {
     char fmt[2];
     va_list args;
@@ -237,8 +237,8 @@ int Ber::scanf(QString format, ...)
     fmt[1] = '\0';
 
     int i = 0, ret = 0;
-    while (i < format.length()) {
-        fmt[0] = format[i].toLatin1();
+    while (format[i]) {
+        fmt[0] = format[i];
         i++;
         switch (fmt[0]) {
         case 'l':
