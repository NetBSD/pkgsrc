$NetBSD: patch-src_unix_thread.c,v 1.6 2019/04/18 07:47:33 adam Exp $

Use feature test for pthread_condattr_setclock, absent in netbsd-6-0

--- src/unix/thread.c.orig	2019-02-10 16:44:47.000000000 +0000
+++ src/unix/thread.c
@@ -687,7 +689,7 @@ int uv_cond_init(uv_cond_t* cond) {
   if (err)
     return UV__ERR(err);
 
-#if !(defined(__ANDROID_API__) && __ANDROID_API__ < 21)
+#if defined(HAVE_PTHREAD_CONDATTR_SETCLOCK)
   err = pthread_condattr_setclock(&attr, CLOCK_MONOTONIC);
   if (err)
     goto error2;
