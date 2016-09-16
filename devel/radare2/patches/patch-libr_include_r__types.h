$NetBSD: patch-libr_include_r__types.h,v 1.1 2016/09/16 14:46:25 jperkin Exp $

Support SunOS.

--- libr/include/r_types.h.orig	2016-05-24 23:34:34.000000000 +0000
+++ libr/include/r_types.h
@@ -50,7 +50,7 @@
 #define MINGW32 1
 #endif
 
-#if defined(EMSCRIPTEN) || defined(__linux__) || defined(__APPLE__) || defined(__GNU__) || defined(__ANDROID__) || defined(__QNX__)
+#if defined(EMSCRIPTEN) || defined(__linux__) || defined(__APPLE__) || defined(__GNU__) || defined(__ANDROID__) || defined(__QNX__) || defined(__sun)
   #define __BSD__ 0
   #define __UNIX__ 1
 #endif
