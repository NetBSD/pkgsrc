$NetBSD: patch-kldap_ber.cpp,v 1.2 2012/11/11 22:28:29 joerg Exp $

Fix building with Clang.

--- kldap/ber.cpp.orig	2012-11-08 10:20:25.000000000 +0000
+++ kldap/ber.cpp
@@ -124,7 +124,7 @@ QByteArray Ber::flatten() const
   return ret;
 }
 
-int Ber::printf( const QString &format, ... )
+int Ber::printf( const char *format, ... )
 {
   char fmt[2];
   va_list args;
@@ -132,8 +132,8 @@ int Ber::printf( const QString &format, 
   fmt[1] = '\0';
 
   int i = 0, ret = 0;
-  while ( i < format.length() ) {
-    fmt[0] = format[i].toLatin1();
+  while ( format[i] ) {
+    fmt[0] = format[i];
     i++;
     switch ( fmt[0] ) {
       case 'b':
@@ -229,7 +229,7 @@ int Ber::printf( const QString &format, 
   return ret;
 }
 
-int Ber::scanf( const QString &format, ... )
+int Ber::scanf( const char *format, ... )
 {
   char fmt[2];
   va_list args;
@@ -237,8 +237,8 @@ int Ber::scanf( const QString &format, .
   fmt[1] = '\0';
 
   int i = 0, ret = 0;
-  while ( i < format.length() ) {
-    fmt[0] = format[i].toLatin1();
+  while ( format[i] ) {
+    fmt[0] = format[i];
     i++;
     switch ( fmt[0] ) {
       case 'l':
