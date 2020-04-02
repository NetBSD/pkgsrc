$NetBSD: patch-src_input_input__http.c,v 1.1 2020/04/02 15:52:46 nia Exp $

Needs sys/socket.h for AF_INET.

--- src/input/input_http.c.orig	2019-12-13 20:47:50.000000000 +0000
+++ src/input/input_http.c
@@ -36,6 +36,8 @@
 
 #ifdef WIN32
 #include <winsock.h>
+#else
+#include <sys/socket.h> /* AF_INET */
 #endif
 
 #define LOG_MODULE "input_http"
