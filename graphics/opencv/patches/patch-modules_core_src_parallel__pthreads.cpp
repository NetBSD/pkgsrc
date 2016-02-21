$NetBSD: patch-modules_core_src_parallel__pthreads.cpp,v 1.2 2016/02/21 14:10:46 fhajny Exp $

PTHREAD_RECURSIVE_MUTEX_INITIALIZER doesn't exist on SunOS.

--- modules/core/src/parallel_pthreads.cpp.orig	2015-12-18 15:02:16.000000000 +0000
+++ modules/core/src/parallel_pthreads.cpp
@@ -221,6 +221,10 @@ private:
     ThreadManagerPoolState m_pool_state;
 };
 
+#ifndef PTHREAD_RECURSIVE_MUTEX_INITIALIZER
+#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER
+#endif
+
 const char ThreadManager::m_env_name[] = "OPENCV_FOR_THREADS_NUM";
 
 #ifdef ANDROID
