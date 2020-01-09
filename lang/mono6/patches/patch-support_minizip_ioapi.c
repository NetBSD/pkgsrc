$NetBSD: patch-support_minizip_ioapi.c,v 1.1 2020/01/09 15:26:36 ryoon Exp $

* NetBSD has no 64-bit functions like macOS.

--- support/minizip/ioapi.c.orig	2019-12-10 07:50:32.000000000 +0000
+++ support/minizip/ioapi.c
@@ -14,7 +14,7 @@
         #define _CRT_SECURE_NO_WARNINGS
 #endif
 
-#if defined(__APPLE__) || defined(IOAPI_NO_64)
+#if defined(__APPLE__) || defined(IOAPI_NO_64) || defined(__NetBSD__)
 // In darwin and perhaps other BSD variants off_t is a 64 bit value, hence no need for specific 64 bit functions
 #define FOPEN_FUNC(filename, mode) fopen(filename, mode)
 #define FTELLO_FUNC(stream) ftello(stream)
