$NetBSD: patch-mono_io-layer_sockets.c,v 1.2 2014/11/30 08:40:51 spz Exp $

Use getprotoent() instead of hardcoding SOL_TCP on NetBSD.

--- mono/io-layer/sockets.c.orig	2014-09-22 13:23:09.000000000 +0000
+++ mono/io-layer/sockets.c
@@ -46,6 +46,9 @@
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <netdb.h>
+#if defined(__NetBSD__)
+#define SOL_TCP getprotoent()
+#endif
 #include <arpa/inet.h>
 #ifdef HAVE_SYS_SENDFILE_H
 #include <sys/sendfile.h>
