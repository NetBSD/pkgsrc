$NetBSD: patch-src_unix_thread.c,v 1.3 2017/08/17 20:06:47 adam Exp $

Use feature test for pthread_condattr_setclock, absent in netbsd-6-0

--- src/unix/thread.c.orig	2017-08-16 14:11:33.000000000 +0000
+++ src/unix/thread.c
@@ -528,7 +528,7 @@ int uv_cond_init(uv_cond_t* cond) {
   if (err)
     return -err;
 
-#if !(defined(__ANDROID_API__) && __ANDROID_API__ < 21)
+#if defined(HAVE_PTHREAD_CONDATTR_SETCLOCK)
   err = pthread_condattr_setclock(&attr, CLOCK_MONOTONIC);
   if (err)
     goto error2;
