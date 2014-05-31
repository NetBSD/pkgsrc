$NetBSD: patch-boehm-gc_include_gc__pthread__redirects.h,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- boehm-gc/include/gc_pthread_redirects.h.orig	2006-08-21 22:07:30.000000000 +0000
+++ boehm-gc/include/gc_pthread_redirects.h
@@ -52,7 +52,7 @@
   int GC_pthread_create(pthread_t *new_thread,
                         const pthread_attr_t *attr,
 		        void *(*start_routine)(void *), void *arg);
-#ifndef GC_DARWIN_THREADS
+#if !defined(GC_DARWIN_THREADS) && !defined(GC_OPENBSD_THREADS)
   int GC_pthread_sigmask(int how, const sigset_t *set, sigset_t *oset);
 #endif
   int GC_pthread_join(pthread_t thread, void **retval);
@@ -72,8 +72,11 @@
 # define pthread_join GC_pthread_join
 # define pthread_detach GC_pthread_detach
 
-#ifndef GC_DARWIN_THREADS
+#if !defined(GC_DARWIN_THREADS) && !defined(GC_OPENBSD_THREADS)
 # define pthread_sigmask GC_pthread_sigmask
+#endif
+
+#ifndef GC_DARWIN_THREADS
 # define dlopen GC_dlopen
 #endif
 
