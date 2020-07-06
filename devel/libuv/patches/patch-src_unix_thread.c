$NetBSD: patch-src_unix_thread.c,v 1.8 2020/07/06 10:07:17 adam Exp $

Use feature test for pthread_condattr_setclock, absent in netbsd-6-0
https://github.com/libuv/libuv/pull/2436

--- src/unix/thread.c.orig	2020-07-03 16:51:27.000000000 +0000
+++ src/unix/thread.c
@@ -709,9 +709,11 @@ int uv_cond_init(uv_cond_t* cond) {
   if (err)
     return UV__ERR(err);
 
+#if defined(HAVE_PTHREAD_CONDATTR_SETCLOCK)
   err = pthread_condattr_setclock(&attr, CLOCK_MONOTONIC);
   if (err)
     goto error2;
+#endif
 
   err = pthread_cond_init(cond, &attr);
   if (err)
