$NetBSD: patch-storage_connect_ioapi.c,v 1.1 2021/05/08 19:47:16 jdolecek Exp $

NetBSD has no fopen64().

--- storage/connect/ioapi.c.orig	2021-02-18 23:22:29.000000000 +0000
+++ storage/connect/ioapi.c
@@ -14,7 +14,7 @@
         #define _CRT_SECURE_NO_WARNINGS
 #endif
 
-#if defined(__APPLE__) || defined(IOAPI_NO_64)
+#if defined(__APPLE__) || defined(__NetBSD__) || defined(IOAPI_NO_64)
 // In darwin and perhaps other BSD variants off_t is a 64 bit value, hence no need for specific 64 bit functions
 #define FOPEN_FUNC(filename, mode) fopen(filename, mode)
 #define FTELLO_FUNC(stream) ftello(stream)
