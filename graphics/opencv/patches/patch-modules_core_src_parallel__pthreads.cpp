$NetBSD: patch-modules_core_src_parallel__pthreads.cpp,v 1.3 2017/09/04 15:23:49 fhajny Exp $

PTHREAD_RECURSIVE_MUTEX_INITIALIZER doesn't exist on SunOS.

--- modules/core/src/parallel_pthreads.cpp.orig	2017-08-03 23:58:23.000000000 +0000
+++ modules/core/src/parallel_pthreads.cpp
@@ -220,6 +220,10 @@ private:
     ThreadManagerPoolState m_pool_state;
 };
 
+#ifndef PTHREAD_RECURSIVE_MUTEX_INITIALIZER
+#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER
+#endif
+
 const char ThreadManager::m_env_name[] = "OPENCV_FOR_THREADS_NUM";
 
 ForThread::~ForThread()
