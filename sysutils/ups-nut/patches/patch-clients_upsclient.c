$NetBSD: patch-clients_upsclient.c,v 1.3 2023/11/09 16:41:15 gdt Exp $

Add missing header for timeval(3) functions.

--- clients/upsclient.c.orig	2023-10-16 08:06:18.000000000 +0000
+++ clients/upsclient.c
@@ -38,6 +38,7 @@
 #ifndef WIN32
 # include <netdb.h>
 # include <sys/socket.h>
+# include <sys/time.h>
 # include <netinet/in.h>
 # include <arpa/inet.h>
 # include <fcntl.h>
