$NetBSD: patch-include_freetds_thread.h,v 1.1 2017/09/17 14:57:59 taca Exp $

* Check _REENTRANT, too.

--- include/freetds/thread.h.orig	2016-05-18 20:02:15.000000000 +0000
+++ include/freetds/thread.h
@@ -24,7 +24,7 @@
 
 #undef TDS_HAVE_MUTEX
 
-#if defined(_THREAD_SAFE) && defined(TDS_HAVE_PTHREAD_MUTEX)
+#if (defined(_REENTRANT) || defined(_THREAD_SAFE)) && defined(TDS_HAVE_PTHREAD_MUTEX)
 
 #include <pthread.h>
 
