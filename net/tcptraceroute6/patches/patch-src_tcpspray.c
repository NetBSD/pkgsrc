$NetBSD: patch-src_tcpspray.c,v 1.1 2020/11/30 12:49:24 nia Exp $

Include signal.h for kill().

--- src/tcpspray.c.orig	2016-12-07 16:43:04.000000000 +0000
+++ src/tcpspray.c
@@ -38,6 +38,7 @@
 #include <unistd.h>
 #include <errno.h>
 #include <sys/socket.h>
+#include <signal.h>
 #include <time.h>
 #include <sys/time.h>
 #include <sys/wait.h>
