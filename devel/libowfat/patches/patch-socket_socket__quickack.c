$NetBSD: patch-socket_socket__quickack.c,v 1.1 2022/01/23 13:30:33 schmonz Exp $

Follow socket/socket_fastopen.c's example to fix Illumos build.

--- socket/socket_quickack.c.orig	2015-04-23 15:15:08.000000000 +0000
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
 #ifdef ENOPROTOOPT
