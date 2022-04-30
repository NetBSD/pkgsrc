$NetBSD: patch-imap_idlemsg.c,v 1.1 2022/04/30 00:25:49 gutteridge Exp $

Fix SunOS build, where "sun" is defined, which clashes with variable naming.

--- imap/idlemsg.c.orig	2017-08-18 00:29:14.000000000 +0000
+++ imap/idlemsg.c
@@ -64,6 +64,11 @@
 #include "idlemsg.h"
 #include "global.h"
 
+/* SunOS defines the macro "sun", which clashes with variable naming here. */
+#ifdef sun
+#undef sun
+#endif
+
 /* UNIX socket variables */
 static int idle_sock = -1;
 static struct sockaddr_un idle_local;
