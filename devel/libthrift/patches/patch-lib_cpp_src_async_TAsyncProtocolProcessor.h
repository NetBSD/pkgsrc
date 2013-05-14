$NetBSD: patch-lib_cpp_src_async_TAsyncProtocolProcessor.h,v 1.1 2013/05/14 19:15:36 joerg Exp $

--- lib/cpp/src/async/TAsyncProtocolProcessor.h.orig	2013-05-03 22:10:39.000000000 +0000
+++ lib/cpp/src/async/TAsyncProtocolProcessor.h
@@ -36,7 +36,7 @@ class TAsyncProtocolProcessor : public T
   {}
 
   virtual void process(
-      std::tr1::function<void(bool healthy)> _return,
+      function<void(bool healthy)> _return,
       boost::shared_ptr<apache::thrift::transport::TBufferBase> ibuf,
       boost::shared_ptr<apache::thrift::transport::TBufferBase> obuf);
 
@@ -44,7 +44,7 @@ class TAsyncProtocolProcessor : public T
 
  private:
   static void finish(
-      std::tr1::function<void(bool healthy)> _return,
+      function<void(bool healthy)> _return,
       boost::shared_ptr<apache::thrift::protocol::TProtocol> oprot,
       bool healthy);
 
