$NetBSD: patch-src_unix_thread.c,v 1.2 2017/03/28 18:44:49 maya Exp $

Use feature test for pthread_condattr_setclock, absent in netbsd-6-0

--- src/unix/thread.c.orig	2017-02-01 00:38:56.000000000 +0000
+++ src/unix/thread.c
@@ -424,7 +424,8 @@ int uv_cond_init(uv_cond_t* cond) {
   if (err)
     return -err;
 
-#if !(defined(__ANDROID__) && defined(HAVE_PTHREAD_COND_TIMEDWAIT_MONOTONIC))
+#if defined(HAVE_PTHREAD_CONDATTR_SETCLOCK) && \
+   (!defined(HAVE_PTHREAD_COND_TIMEDWAIT_MONOTONIC))
   err = pthread_condattr_setclock(&attr, CLOCK_MONOTONIC);
   if (err)
     goto error2;
