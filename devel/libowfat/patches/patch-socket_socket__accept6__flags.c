$NetBSD: patch-socket_socket__accept6__flags.c,v 1.1 2023/11/09 19:26:00 schmonz Exp $

Don't use socket flags when they're not available.

--- socket/socket_accept6_flags.c.orig	2021-04-27 17:39:44.000000000 +0000
+++ socket/socket_accept6_flags.c
@@ -98,8 +98,12 @@ incoming:
       fd=-1;
     else {
       int flg=0;
+#ifdef SOCK_NONBLOCK
       if (flags & SOCKET_NONBLOCK) flg += SOCK_NONBLOCK;
+#endif
+#ifdef SOCK_CLOEXEC
       if (flags & SOCKET_CLOEXEC) flg += SOCK_CLOEXEC;
+#endif
       if ((fd=accept4(s,(void*) &sa, &dummy, flg))==-1) {
 	if (errno != ENOSYS)
 	  return -1;
