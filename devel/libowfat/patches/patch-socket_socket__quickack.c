$NetBSD: patch-socket_socket__quickack.c,v 1.2 2023/11/09 19:26:00 schmonz Exp $

Follow socket/socket_fastopen.c's example to fix Illumos build.

--- socket/socket_quickack.c.orig	2019-02-21 12:39:44.000000000 +0000
+++ socket/socket_quickack.c
@@ -6,8 +6,12 @@
 #endif
 #include <errno.h>
 
+#if defined(TCP_QUICKACK) && !defined(SOL_TCP) && defined(IPPROTO_TCP)
+#define SOL_TCP IPPROTO_TCP
+#endif
+
 int socket_quickack(int s,int value) {
-#ifdef TCP_QUICKACK
+#if defined(SOL_TCP) && defined(TCP_QUICKACK)
   return setsockopt(s, SOL_TCP, TCP_QUICKACK, &value, sizeof(int));
 #else
   (void)s;	// shut up unused variable warnings
