$NetBSD: patch-libsrc_Thread_sched_pthread.c,v 1.1 2013/04/13 13:16:02 jaapb Exp $

NetBSD does not have this (optional) pthread function, ignore it
--- libsrc/Thread/sched_pthread.c.orig	2012-08-01 20:54:31.000000000 +0000
+++ libsrc/Thread/sched_pthread.c
@@ -206,7 +206,7 @@ thread_initial (unsigned long stack_size
   CKRET (rc);
 #endif
 
-#if defined (PTHREAD_PROCESS_PRIVATE) && !defined(oldlinux) && !defined(__FreeBSD__)
+#if defined (PTHREAD_PROCESS_PRIVATE) && !defined(oldlinux) && !defined(__FreeBSD__) && !defined(__NetBSD__)
   rc = pthread_mutexattr_setpshared (&_mutex_attr, PTHREAD_PROCESS_PRIVATE);
   CKRET (rc);
 #endif
@@ -1075,7 +1075,7 @@ mutex_allocate_typed (int type)
       if (!is_initialized)
 	{
 	  pthread_mutexattr_init (&_mutex_attr);
-#if defined (PTHREAD_PROCESS_PRIVATE) && !defined(oldlinux) && !defined (__FreeBSD__)	  
+#if defined (PTHREAD_PROCESS_PRIVATE) && !defined(oldlinux) && !defined (__FreeBSD__)	&& !defined(__NetBSD__)
 	  rc = pthread_mutexattr_setpshared (&_mutex_attr, PTHREAD_PROCESS_PRIVATE);
 	  CKRET (rc);
 #endif
@@ -1132,7 +1132,7 @@ dk_mutex_init (dk_mutex_t * mtx, int typ
       if (!is_initialized) 
 	{
 	  pthread_mutexattr_init (&_attr);
-#if defined (PTHREAD_PROCESS_PRIVATE) && !defined (__FreeBSD__) && !defined(oldlinux)
+#if defined (PTHREAD_PROCESS_PRIVATE) && !defined (__FreeBSD__) && !defined(__NetBSD__) && !defined(oldlinux)
 	  rc = pthread_mutexattr_setpshared (&_attr, PTHREAD_PROCESS_PRIVATE);
 	  CKRET (rc);
 #endif	  
