$NetBSD: patch-lib_cpp_src_async_TAsyncBufferProcessor.h,v 1.1 2013/05/14 19:15:36 joerg Exp $

--- lib/cpp/src/async/TAsyncBufferProcessor.h.orig	2013-05-03 22:09:56.000000000 +0000
+++ lib/cpp/src/async/TAsyncBufferProcessor.h
@@ -20,13 +20,23 @@
 #ifndef _THRIFT_TASYNC_BUFFER_PROCESSOR_H_
 #define _THRIFT_TASYNC_BUFFER_PROCESSOR_H_ 1
 
+#if __cplusplus >= 201103L
+#include <functional>
+#else
 #include <tr1/functional>
+#endif
 #include <boost/shared_ptr.hpp>
 
 #include "transport/TBufferTransports.h"
 
 namespace apache { namespace thrift { namespace async {
 
+#if __cplusplus >= 201103L
+using std::function;
+#else
+using std::tr1::function;
+#endif
+
 class TAsyncBufferProcessor {
  public:
   // Process data in "in", putting the result in "out".
@@ -35,7 +45,7 @@ class TAsyncBufferProcessor {
   // "in" and "out" should be TMemoryBuffer or similar,
   // not a wrapper around a socket.
   virtual void process(
-      std::tr1::function<void(bool healthy)> _return,
+      function<void(bool healthy)> _return,
       boost::shared_ptr<apache::thrift::transport::TBufferBase> ibuf,
       boost::shared_ptr<apache::thrift::transport::TBufferBase> obuf) = 0;
   virtual ~TAsyncBufferProcessor() {}
