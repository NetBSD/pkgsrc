$NetBSD: patch-src_read__tcp.c,v 1.1 2013/10/13 12:08:21 imil Exp $

Added sys/time and sys/select includes in order to read_tcp to build

--- src/read_tcp.c.orig	2013-10-13 11:55:00.000000000 +0000
+++ src/read_tcp.c
@@ -36,6 +36,8 @@
 #include <string.h>
 #include <unistd.h>
 #include <netinet/in.h>
+#include <sys/time.h>
+#include <sys/select.h>
 
 struct read_tcp_data {
 	char *host;
