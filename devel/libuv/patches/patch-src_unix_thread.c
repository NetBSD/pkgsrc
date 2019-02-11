$NetBSD: patch-src_unix_thread.c,v 1.5 2019/02/11 10:46:56 adam Exp $

Fix for systems without PTHREAD_STACK_MIN.
Use feature test for pthread_condattr_setclock, absent in netbsd-6-0

--- src/unix/thread.c.orig	2019-02-10 16:44:47.000000000 +0000
+++ src/unix/thread.c
@@ -219,9 +219,11 @@ int uv_thread_create_ex(uv_thread_t* tid
     pagesize = (size_t)getpagesize();
     /* Round up to the nearest page boundary. */
     stack_size = (stack_size + pagesize - 1) &~ (pagesize - 1);
+#ifdef PTHREAD_STACK_MIN
     if (stack_size < PTHREAD_STACK_MIN)
       stack_size = PTHREAD_STACK_MIN;
+#endif
   }
 
   if (stack_size > 0) {
     attr = &attr_storage;
@@ -685,7 +687,7 @@ int uv_cond_init(uv_cond_t* cond) {
   if (err)
     return UV__ERR(err);
 
-#if !(defined(__ANDROID_API__) && __ANDROID_API__ < 21)
+#if defined(HAVE_PTHREAD_CONDATTR_SETCLOCK)
   err = pthread_condattr_setclock(&attr, CLOCK_MONOTONIC);
   if (err)
     goto error2;
