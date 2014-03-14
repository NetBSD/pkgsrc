$NetBSD: patch-thread__pthread.c,v 1.1 2014/03/14 19:40:47 taca Exp $

Correct usage of pthread_setname_np() on NetBSD.

--- thread_pthread.c.orig	2014-02-22 07:17:22.000000000 +0000
+++ thread_pthread.c
@@ -1424,8 +1424,12 @@ timer_thread_sleep(rb_global_vm_lock_t* 
 #if defined(__linux__) && defined(PR_SET_NAME)
 # define SET_THREAD_NAME(name) prctl(PR_SET_NAME, name)
 #elif defined(HAVE_PTHREAD_SETNAME_NP)
+#ifdef __NetBSD__
+# define SET_THREAD_NAME(name) pthread_setname_np(pthread_self(), "%s", ((name)))
+#else
 /* pthread_setname_np() on Darwin does not have target thread argument */
 # define SET_THREAD_NAME(name) pthread_setname_np(name)
+#endif
 #else
 # define SET_THREAD_NAME(name) (void)0
 #endif
