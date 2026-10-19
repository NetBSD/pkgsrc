$NetBSD: patch-src_sockets.c,v 1.1 2026/10/19 23:09:37 gutteridge Exp $

Include proper header for select(2).

--- src/sockets.c.orig	2017-08-25 19:59:05.000000000 +0000
+++ src/sockets.c
@@ -25,6 +25,7 @@
 #include <stddef.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/select.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <netinet/in.h>
