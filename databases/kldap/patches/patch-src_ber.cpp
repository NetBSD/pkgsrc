$NetBSD: patch-src_ber.cpp,v 1.3 2022/09/29 00:26:00 markd Exp $

--- src/core/ber.cpp.orig	2022-08-05 11:31:27.000000000 +0000
+++ src/core/ber.cpp
@@ -110,7 +110,7 @@ QByteArray Ber::flatten() const
     return ret;
 }
 
-int Ber::printf(QString format, ...)
+int Ber::printf(const char *format, ...)
 {
     char fmt[2];
     va_list args;
@@ -119,8 +119,8 @@ int Ber::printf(QString format, ...)
 
     int i = 0;
     int ret = 0;
-    while (i < format.length()) {
-        fmt[0] = format[i].toLatin1();
+    while (format[i]) {
+        fmt[0] = format[i];
         i++;
         switch (fmt[0]) {
         case 'b':
@@ -206,7 +206,7 @@ int Ber::printf(QString format, ...)
     return ret;
 }
 
-int Ber::scanf(QString format, ...)
+int Ber::scanf(const char *format, ...)
 {
     char fmt[2];
     va_list args;
@@ -215,8 +215,8 @@ int Ber::scanf(QString format, ...)
 
     int i = 0;
     int ret = 0;
-    while (i < format.length()) {
-        fmt[0] = format[i].toLatin1();
+    while (format[i]) {
+        fmt[0] = format[i];
         i++;
         switch (fmt[0]) {
         case 'l':
