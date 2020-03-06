$NetBSD: patch-src_eXutils.c,v 1.1 2020/03/06 13:01:47 nia Exp $

Defines INADDR_NONE, which is needed on Solaris.

--- src/eXutils.c.orig	2020-01-17 12:52:50.000000000 +0000
+++ src/eXutils.c
@@ -84,6 +84,10 @@
 #include <unistd.h>
 #endif
 
+#ifndef INADDR_NONE
+#define INADDR_NONE	((unsigned long) -1)	/* needed on Solaris */
+#endif
+
 int
 _eXosip_closesocket (SOCKET_TYPE sock)
 {
