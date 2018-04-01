$NetBSD: patch-clients_upsclient.c,v 1.1 2018/04/01 20:29:28 joerg Exp $

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
