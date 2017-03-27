$NetBSD: patch-src_unix_thread.c,v 1.1 2017/03/27 15:34:00 maya Exp $

Don't use pthread_condattr_setclock on NetBSD. It's effectively
a no-op, and doesn't exist on NetBSD<7 leading to undefined refs
in building cmake.

--- src/unix/thread.c.orig	2017-02-01 00:38:56.000000000 +0000
+++ src/unix/thread.c
@@ -424,7 +424,8 @@ int uv_cond_init(uv_cond_t* cond) {
   if (err)
     return -err;
 
-#if !(defined(__ANDROID__) && defined(HAVE_PTHREAD_COND_TIMEDWAIT_MONOTONIC))
+#if !(defined(__ANDROID__) && defined(HAVE_PTHREAD_COND_TIMEDWAIT_MONOTONIC)) && \
+    !(defined(__NetBSD__))
   err = pthread_condattr_setclock(&attr, CLOCK_MONOTONIC);
   if (err)
     goto error2;
