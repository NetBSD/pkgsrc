$NetBSD: patch-boost_thread_pthread_thread__data.hpp,v 1.1 2018/12/14 11:56:48 jperkin Exp $

PTHREAD_STACK_MIN on SunOS is not a constant.

--- boost/thread/pthread/thread_data.hpp.orig	2018-12-14 11:22:44.619793412 +0000
+++ boost/thread/pthread/thread_data.hpp
@@ -32,6 +32,7 @@
 # endif
 #endif
 
+#include <limits.h>
 #include <pthread.h>
 #include <unistd.h>
 
@@ -57,7 +58,9 @@ namespace boost
 #else
           std::size_t page_size = ::sysconf( _SC_PAGESIZE);
 #endif
-#if PTHREAD_STACK_MIN > 0
+#if defined(__sun)
+          if (size<PTHREAD_STACK_MIN) size=PTHREAD_STACK_MIN;
+#elif PTHREAD_STACK_MIN > 0
           if (size<PTHREAD_STACK_MIN) size=PTHREAD_STACK_MIN;
 #endif
           size = ((size+page_size-1)/page_size)*page_size;
