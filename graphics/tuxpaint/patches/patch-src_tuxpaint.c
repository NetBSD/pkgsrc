$NetBSD: patch-src_tuxpaint.c,v 1.1 2014/09/24 11:27:51 jperkin Exp $

Fix build on SunOS.

--- src/tuxpaint.c.orig	2014-08-23 19:21:06.000000000 +0000
+++ src/tuxpaint.c
@@ -549,7 +549,7 @@ static void mtw(wchar_t * wtok, char * t
 
 //#define fmemopen_alternative */ /* Uncomment this to test the fmemopen alternative in systems were fmemopen exists */
 
-#if defined (WIN32) || defined (__APPLE__) || defined(__NetBSD__) // MINGW/MSYS, NetBSD, and MacOSX need it, at least for now
+#if defined (WIN32) || defined (__APPLE__) || defined(__NetBSD__) || defined(__sun) // MINGW/MSYS, NetBSD, and MacOSX need it, at least for now
 #define fmemopen_alternative 
 #endif
 
