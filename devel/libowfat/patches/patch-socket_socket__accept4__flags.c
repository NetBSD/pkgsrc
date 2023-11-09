$NetBSD: patch-socket_socket__accept4__flags.c,v 1.1 2023/11/09 19:26:00 schmonz Exp $

Don't use socket flags when they're not available.

--- socket/socket_accept4_flags.c.orig	2021-04-27 17:39:43.000000000 +0000
+++ socket/socket_accept4_flags.c
@@ -84,8 +84,12 @@ incoming:
       fd=-1;
     else {
       int flg=0;
+#ifdef SOCK_NONBLOCK
       if (flags & SOCKET_NONBLOCK) flg += SOCK_NONBLOCK;
+#endif
+#ifdef SOCK_CLOEXEC
       if (flags & SOCKET_CLOEXEC) flg += SOCK_CLOEXEC;
+#endif
       if ((fd=accept4(s,(void*) &si, &len, flg))==-1) {
 	if (errno != ENOSYS)
 	  return -1;
