$NetBSD: patch-lib_cpp_src_concurrency_FunctionRunner.h,v 1.1 2013/05/14 19:15:36 joerg Exp $

--- lib/cpp/src/concurrency/FunctionRunner.h.orig	2013-04-28 06:41:56.000000000 +0000
+++ lib/cpp/src/concurrency/FunctionRunner.h
@@ -20,7 +20,11 @@
 #ifndef _THRIFT_CONCURRENCY_FUNCTION_RUNNER_H
 #define _THRIFT_CONCURRENCY_FUNCTION_RUNNER_H 1
 
+#if __cplusplus >= 201103L
+#include <functional>
+#else
 #include <tr1/functional>
+#endif
 #include "thrift/lib/cpp/concurrency/Thread.h"
 
 namespace apache { namespace thrift { namespace concurrency {
@@ -52,16 +56,25 @@ class FunctionRunner : public Runnable {
   // This is the type of callback 'pthread_create()' expects.
   typedef void* (*PthreadFuncPtr)(void *arg);
   // This a fully-generic void(void) callback for custom bindings.
+#if __cplusplus >= 201103L
+  typedef std::function<void()> VoidFunc;
+  typedef std::function<bool()> BoolFunc;
+#else
   typedef std::tr1::function<void()> VoidFunc;
-
   typedef std::tr1::function<bool()> BoolFunc;
+#endif
 
   /**
    * Given a 'pthread_create' style callback, this FunctionRunner will
    * execute the given callback.  Note that the 'void*' return value is ignored.
    */
+#if __cplusplus >= 201103L
+  FunctionRunner(PthreadFuncPtr func, void* arg)
+   : func_(std::bind(func, arg)), repFunc_(0)
+#else
   FunctionRunner(PthreadFuncPtr func, void* arg)
    : func_(std::tr1::bind(func, arg)), repFunc_(0)
+#endif
   { }
 
   /**
