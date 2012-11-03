$NetBSD: patch-sysdeputil.c,v 1.1 2012/11/03 13:45:00 wiz Exp $

Fix build on DragonFlyBSD.

--- sysdeputil.c.orig	2010-03-26 03:25:33.000000000 +0000
+++ sysdeputil.c
@@ -116,6 +116,11 @@
   #endif
 #endif
 
+#if defined(__DragonFly__)
+  #define VSF_SYSDEP_HAVE_SETPROCTITLE
+  #define WTMPX_FILE _PATH_WTMPX
+#endif
+
 #ifdef __hpux
   #include <sys/socket.h>
   #ifdef SF_DISCONNECT
