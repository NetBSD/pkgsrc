$NetBSD: patch-pdns_webserver.cc,v 1.1 2020/05/16 02:14:47 joerg Exp $

--- pdns/webserver.cc.orig	2020-05-14 23:32:52.641862905 +0000
+++ pdns/webserver.cc
@@ -107,7 +107,7 @@ static void bareHandlerWrapper(WebServer
 
 void WebServer::registerBareHandler(const string& url, HandlerFunction handler)
 {
-  YaHTTP::THandlerFunction f = boost::bind(&bareHandlerWrapper, handler, _1, _2);
+  YaHTTP::THandlerFunction f = boost::bind(&bareHandlerWrapper, handler, boost::placeholders::_1, boost::placeholders::_2);
   YaHTTP::Router::Any(url, f);
 }
 
@@ -179,7 +179,7 @@ void WebServer::apiWrapper(WebServer::Ha
 }
 
 void WebServer::registerApiHandler(const string& url, HandlerFunction handler, bool allowPassword) {
-  HandlerFunction f = boost::bind(&WebServer::apiWrapper, this, handler, _1, _2, allowPassword);
+  HandlerFunction f = boost::bind(&WebServer::apiWrapper, this, handler, boost::placeholders::_1, boost::placeholders::_2, allowPassword);
   registerBareHandler(url, f);
 }
 
@@ -196,7 +196,7 @@ void WebServer::webWrapper(WebServer::Ha
 }
 
 void WebServer::registerWebHandler(const string& url, HandlerFunction handler) {
-  HandlerFunction f = boost::bind(&WebServer::webWrapper, this, handler, _1, _2);
+  HandlerFunction f = boost::bind(&WebServer::webWrapper, this, handler, boost::placeholders::_1, boost::placeholders::_2);
   registerBareHandler(url, f);
 }
 
