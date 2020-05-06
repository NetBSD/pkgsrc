$NetBSD: patch-boost_thread_pthread_thread__data.hpp,v 1.2 2020/05/06 13:33:53 adam Exp $

--- boost/thread/pthread/thread_data.hpp.orig	2020-04-22 13:36:07.000000000 +0000
+++ boost/thread/pthread/thread_data.hpp
@@ -32,6 +32,7 @@
 # endif
 #endif
 
+#include <limits.h>
 #include <pthread.h>
 #include <unistd.h>
 
