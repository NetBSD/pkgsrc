$NetBSD: patch-src_relayd.c,v 1.1 2019/01/05 21:46:05 schmonz Exp $

Copy default MSG_NOSIGNAL from src/privproc.c.

--- src/relayd.c.orig	2013-05-23 15:40:42.000000000 +0000
+++ src/relayd.c
@@ -48,6 +48,9 @@
 #ifdef HAVE_SYS_CAPABILITY_H
 # include <sys/capability.h>
 #endif
+#ifndef MSG_NOSIGNAL
+# define MSG_NOSIGNAL 0 /* Uho */
+#endif
 #ifndef SOL_IPV6
 # define SOL_IPV6 IPPROTO_IPV6
 #endif
