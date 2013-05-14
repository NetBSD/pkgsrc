$NetBSD: patch-lib_cpp_src_async_TAsyncProcessor.h,v 1.1 2013/05/14 19:15:36 joerg Exp $

--- lib/cpp/src/async/TAsyncProcessor.h.orig	2013-05-03 22:08:23.000000000 +0000
+++ lib/cpp/src/async/TAsyncProcessor.h
@@ -20,13 +20,23 @@
 #ifndef _THRIFT_TASYNCPROCESSOR_H_
 #define _THRIFT_TASYNCPROCESSOR_H_ 1
 
+#if __cplusplus >= 201103L
+#include <functional>
+#else
 #include <tr1/functional>
+#endif
 #include <boost/shared_ptr.hpp>
 #include <protocol/TProtocol.h>
 #include <TProcessor.h>
 
 namespace apache { namespace thrift { namespace async {
 
+#if __cplusplus >= 201103L
+using std::function;
+#else
+using std::tr1::function;
+#endif
+
 /**
  * Async version of a TProcessor.  It is not expected to complete by the time
  * the call to process returns.  Instead, it calls a cob to signal completion.
@@ -38,11 +48,11 @@ class TAsyncProcessor {
  public:
   virtual ~TAsyncProcessor() {}
 
-  virtual void process(std::tr1::function<void(bool success)> _return,
+  virtual void process(function<void(bool success)> _return,
                        boost::shared_ptr<protocol::TProtocol> in,
                        boost::shared_ptr<protocol::TProtocol> out) = 0;
 
-  void process(std::tr1::function<void(bool success)> _return,
+  void process(function<void(bool success)> _return,
                boost::shared_ptr<apache::thrift::protocol::TProtocol> io) {
     return process(_return, io, io);
   }
