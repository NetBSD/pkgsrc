$NetBSD: patch-src_unix_thread.c,v 1.4 2018/02/22 08:44:15 adam Exp $

Use feature test for pthread_condattr_setclock, absent in netbsd-6-0

--- src/unix/thread.c.orig	2018-02-21 20:25:38.000000000 +0000
+++ src/unix/thread.c
@@ -568,7 +568,7 @@ int uv_cond_init(uv_cond_t* cond) {
   if (err)
     return UV__ERR(err);
 
-#if !(defined(__ANDROID_API__) && __ANDROID_API__ < 21)
+#if defined(HAVE_PTHREAD_CONDATTR_SETCLOCK)
   err = pthread_condattr_setclock(&attr, CLOCK_MONOTONIC);
   if (err)
     goto error2;
