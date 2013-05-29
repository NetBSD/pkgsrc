$NetBSD: patch-mono_io-layer_sockets.c,v 1.1 2013/05/29 11:11:12 wiz Exp $

Use getprotoent() instead of hardcoding SOL_TCP on NetBSD.

--- mono/io-layer/sockets.c.orig	2012-12-05 17:44:35.000000000 +0000
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
