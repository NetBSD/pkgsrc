$NetBSD: patch-lib_cpp_src_async_TAsyncProtocolProcessor.cpp,v 1.1 2013/05/14 19:15:36 joerg Exp $

--- lib/cpp/src/async/TAsyncProtocolProcessor.cpp.orig	2013-05-03 22:11:00.000000000 +0000
+++ lib/cpp/src/async/TAsyncProtocolProcessor.cpp
@@ -24,23 +24,31 @@ using apache::thrift::protocol::TProtoco
 
 namespace apache { namespace thrift { namespace async {
 
+#if __cplusplus >= 201103L
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
+
 void TAsyncProtocolProcessor::process(
-    std::tr1::function<void(bool healthy)> _return,
+    function<void(bool healthy)> _return,
     boost::shared_ptr<TBufferBase> ibuf,
     boost::shared_ptr<TBufferBase> obuf) {
   boost::shared_ptr<TProtocol> iprot(pfact_->getProtocol(ibuf));
   boost::shared_ptr<TProtocol> oprot(pfact_->getProtocol(obuf));
   return underlying_->process(
-      std::tr1::bind(
+      bind(
         &TAsyncProtocolProcessor::finish,
         _return,
         oprot,
-        std::tr1::placeholders::_1),
+        STD_PLACEHOLDERS::_1),
       iprot, oprot);
 }
 
 /* static */ void TAsyncProtocolProcessor::finish(
-    std::tr1::function<void(bool healthy)> _return,
+    function<void(bool healthy)> _return,
     boost::shared_ptr<TProtocol> oprot,
     bool healthy) {
   (void) oprot;
