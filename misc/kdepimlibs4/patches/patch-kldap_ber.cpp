$NetBSD: patch-kldap_ber.cpp,v 1.1 2012/09/30 13:15:04 adam Exp $

Fix building with Clang.

--- kldap/ber.cpp.orig	2012-09-30 12:13:44.000000000 +0000
+++ kldap/ber.cpp
@@ -128,7 +128,11 @@ int Ber::printf( const QString &format, 
 {
   char fmt[2];
   va_list args;
+#ifdef __clang__
+  va_start ( args, format.unicode() );
+#else
   va_start ( args, format );
+#endif
   fmt[1] = '\0';
 
   int i = 0, ret = 0;
@@ -233,7 +237,11 @@ int Ber::scanf( const QString &format, .
 {
   char fmt[2];
   va_list args;
+#ifdef __clang__
+  va_start ( args, format.unicode() );
+#else
   va_start ( args, format );
+#endif
   fmt[1] = '\0';
 
   int i = 0, ret = 0;
