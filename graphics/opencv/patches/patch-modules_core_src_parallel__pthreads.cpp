$NetBSD: patch-modules_core_src_parallel__pthreads.cpp,v 1.1 2015/10/08 17:45:59 fhajny Exp $

PTHREAD_RECURSIVE_MUTEX_INITIALIZER doesn't exist on SunOS.

--- modules/core/src/parallel_pthreads.cpp.orig	2015-06-03 17:21:34.000000000 +0000
+++ modules/core/src/parallel_pthreads.cpp
@@ -244,6 +244,10 @@ private:
     ThreadManagerPoolState m_pool_state;
 };
 
+#ifndef PTHREAD_RECURSIVE_MUTEX_INITIALIZER
+#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER
+#endif
+
 #ifndef PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
 #define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP PTHREAD_RECURSIVE_MUTEX_INITIALIZER
 #endif
