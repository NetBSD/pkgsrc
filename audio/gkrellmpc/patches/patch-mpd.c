$NetBSD: patch-mpd.c,v 1.1 2021/11/27 10:37:24 pho Exp $

Fix build on NetBSD: struct sockaddr_in is not defined unless
<netinet/in.h> is #include'd.

--- mpd.c.orig	2021-11-27 10:11:28.288468327 +0000
+++ mpd.c
@@ -11,6 +11,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netdb.h>
+#include <netinet/in.h>
 
 GIOChannel   * mpc_mpd = NULL;
 
