$NetBSD: patch-src_unix_kqueue.c,v 1.2 2022/05/16 07:21:35 wiz Exp $

Fix cmake hang.
https://github.com/libuv/libuv/pull/3629

--- src/unix/kqueue.c.orig	2022-03-09 17:54:54.000000000 +0000
+++ src/unix/kqueue.c
@@ -456,7 +456,7 @@ void uv__platform_invalidate_fd(uv_loop_
 
   /* Invalidate events with same file descriptor */
   for (i = 0; i < nfds; i++)
-    if ((int) events[i].ident == fd)
+    if ((int) events[i].ident == fd && events[i].filter != EVFILT_PROC)
       events[i].ident = -1;
 }
 
