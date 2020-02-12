$NetBSD: patch-support_minizip_ioapi.c,v 1.2 2020/02/12 15:25:16 ryoon Exp $

* NetBSD has no 64-bit functions like macOS.

--- support/minizip/ioapi.c.orig	2020-02-04 17:00:34.000000000 +0000
+++ support/minizip/ioapi.c
@@ -14,7 +14,7 @@
         #define _CRT_SECURE_NO_WARNINGS
 #endif
 
-#if defined(__APPLE__) || defined(IOAPI_NO_64) || defined(__HAIKU__)
+#if defined(__APPLE__) || defined(IOAPI_NO_64) || defined(__HAIKU__) || defined(__NetBSD__)
 // In darwin and perhaps other BSD variants off_t is a 64 bit value, hence no need for specific 64 bit functions
 #define FOPEN_FUNC(filename, mode) fopen(filename, mode)
 #define FTELLO_FUNC(stream) ftello(stream)
