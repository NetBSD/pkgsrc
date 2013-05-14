$NetBSD: patch-lib_cpp_src_async_TEvhttpServer.cpp,v 1.1 2013/05/14 19:15:36 joerg Exp $

--- lib/cpp/src/async/TEvhttpServer.cpp.orig	2013-05-03 22:12:02.000000000 +0000
+++ lib/cpp/src/async/TEvhttpServer.cpp
@@ -30,6 +30,13 @@ using apache::thrift::transport::TMemory
 
 namespace apache { namespace thrift { namespace async {
 
+#if __cplusplus >= 201103L
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
 
 struct TEvhttpServer::RequestContext {
   struct evhttp_request* req;
@@ -113,11 +120,11 @@ void TEvhttpServer::request(struct evhtt
 void TEvhttpServer::process(struct evhttp_request* req) {
   RequestContext* ctx = new RequestContext(req);
   return processor_->process(
-      std::tr1::bind(
+      bind(
         &TEvhttpServer::complete,
         this,
         ctx,
-        std::tr1::placeholders::_1),
+        STD_PLACEHOLDERS::_1),
       ctx->ibuf,
       ctx->obuf);
 }
