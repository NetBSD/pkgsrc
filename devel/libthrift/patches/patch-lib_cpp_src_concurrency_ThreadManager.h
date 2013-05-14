$NetBSD: patch-lib_cpp_src_concurrency_ThreadManager.h,v 1.1 2013/05/14 19:15:36 joerg Exp $

--- lib/cpp/src/concurrency/ThreadManager.h.orig	2013-04-28 06:39:26.000000000 +0000
+++ lib/cpp/src/concurrency/ThreadManager.h
@@ -21,7 +21,11 @@
 #define _THRIFT_CONCURRENCY_THREADMANAGER_H_ 1
 
 #include <boost/shared_ptr.hpp>
+#if  __cplusplus >= 201103L
+#include <functional>
+#else
 #include <tr1/functional>
+#endif
 #include <sys/types.h>
 #include "Thread.h"
 
@@ -58,7 +62,11 @@ class ThreadManager {
 
  public:
   class Task;
+#if  __cplusplus >= 201103L
+  typedef std::function<void(boost::shared_ptr<Runnable>)> ExpireCallback;
+#else
   typedef std::tr1::function<void(boost::shared_ptr<Runnable>)> ExpireCallback;
+#endif
 
   virtual ~ThreadManager() {}
 
