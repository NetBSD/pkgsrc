$NetBSD: patch-src_eXutils.c,v 1.2 2020/12/06 23:40:21 schwarz Exp $

Defines INADDR_NONE, which is needed on Solaris.

--- src/eXutils.c.orig	2020-12-07 00:12:50.000000000 +0100
+++ src/eXutils.c	2020-12-07 00:14:34.000000000 +0100
@@ -79,6 +79,10 @@
 #include <unistd.h>
 #endif
 
+#ifndef INADDR_NONE
+#define INADDR_NONE	((unsigned long) -1)	/* needed on Solaris */
+#endif
+
 int _eXosip_closesocket(SOCKET_TYPE sock) {
 #if !defined(HAVE_WINSOCK2_H)
   return close(sock);
