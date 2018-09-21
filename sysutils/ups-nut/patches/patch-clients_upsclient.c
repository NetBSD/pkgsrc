$NetBSD: patch-clients_upsclient.c,v 1.2 2018/09/21 00:59:53 jym Exp $

Add missing header for timeval(3) functions.

--- clients/upsclient.c.orig	2018-04-01 17:13:02.200981408 +0000
+++ clients/upsclient.c
@@ -28,6 +28,7 @@
 #include <string.h>
 #include <unistd.h>
 #include <sys/socket.h>
+#include <sys/time.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <fcntl.h>
