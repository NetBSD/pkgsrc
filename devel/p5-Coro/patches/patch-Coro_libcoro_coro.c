$NetBSD: patch-Coro_libcoro_coro.c,v 1.2 2023/11/24 16:32:37 wiz Exp $

Workaround for libpthread bug in NetBSD, see PR 57721.

--- Coro/libcoro/coro.c.orig	2018-08-14 15:37:40.000000000 +0000
+++ Coro/libcoro/coro.c
@@ -578,6 +578,10 @@ coro_create (coro_context *ctx, coro_fun
       /* POSIX, not here */
       pthread_attr_setstacksize (&attr, (size_t)ssize);
 #else
+#ifdef __NetBSD__
+      /* workaround for a bug in libpthread; the guard size should be ignored, but isn't */
+      pthread_attr_setguardsize (&attr, 0);
+#endif
       pthread_attr_setstack (&attr, sptr, (size_t)ssize);
 #endif
       pthread_attr_setscope (&attr, PTHREAD_SCOPE_PROCESS);
