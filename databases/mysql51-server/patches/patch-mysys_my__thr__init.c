$NetBSD: patch-mysys_my__thr__init.c,v 1.1 2013/08/22 11:09:46 christos Exp $

Check for the gethostbyname declaration before using it.

--- mysys/my_thr_init.c.orig	2013-07-11 16:39:36.000000000 +0300
+++ mysys/my_thr_init.c	2013-08-22 12:56:33.000000000 +0300
@@ -42,7 +42,7 @@
 #if !defined(HAVE_LOCALTIME_R) || !defined(HAVE_GMTIME_R)
 pthread_mutex_t LOCK_localtime_r;
 #endif
-#ifndef HAVE_GETHOSTBYNAME_R
+#if !defined(HAVE_GETHOSTBYNAME_R) || !HAVE_DECL_GETHOSTBYNAME_R
 pthread_mutex_t LOCK_gethostbyname_r;
 #endif
 #ifdef PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP
@@ -162,7 +162,7 @@
 #if !defined(HAVE_LOCALTIME_R) || !defined(HAVE_GMTIME_R)
   pthread_mutex_init(&LOCK_localtime_r,MY_MUTEX_INIT_SLOW);
 #endif
-#ifndef HAVE_GETHOSTBYNAME_R
+#if !defined(HAVE_GETHOSTBYNAME_R) || !HAVE_DECL_GETHOSTBYNAME_R
   pthread_mutex_init(&LOCK_gethostbyname_r,MY_MUTEX_INIT_SLOW);
 #endif
   if (my_thread_init())
@@ -229,7 +229,7 @@
 #if !defined(HAVE_LOCALTIME_R) || !defined(HAVE_GMTIME_R)
   pthread_mutex_destroy(&LOCK_localtime_r);
 #endif
-#ifndef HAVE_GETHOSTBYNAME_R
+#if !defined(HAVE_GETHOSTBYNAME_R) || !HAVE_DECL_GETHOSTBYNAME_R
   pthread_mutex_destroy(&LOCK_gethostbyname_r);
 #endif
 }
