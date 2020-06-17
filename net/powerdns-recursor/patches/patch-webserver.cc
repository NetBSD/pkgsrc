$NetBSD: patch-webserver.cc,v 1.1 2020/06/17 22:55:11 otis Exp $

boost 1.73 moved placeholders into std::placeholders namespace
backport changes based on PR #9070 from
https://github.com/PowerDNS/pdns/pull/9070/

--- webserver.cc.orig	2020-05-08 09:30:45.000000000 +0000
+++ webserver.cc
@@ -107,7 +107,7 @@ static void bareHandlerWrapper(WebServer
 
 void WebServer::registerBareHandler(const string& url, HandlerFunction handler)
 {
-  YaHTTP::THandlerFunction f = boost::bind(&bareHandlerWrapper, handler, _1, _2);
+  YaHTTP::THandlerFunction f = std::bind(&bareHandlerWrapper, handler, std::placeholders::_1, std::placeholders::_2);
   YaHTTP::Router::Any(url, f);
 }
 
@@ -179,7 +179,7 @@ void WebServer::apiWrapper(WebServer::Ha
 }
 
 void WebServer::registerApiHandler(const string& url, HandlerFunction handler, bool allowPassword) {
-  HandlerFunction f = boost::bind(&WebServer::apiWrapper, this, handler, _1, _2, allowPassword);
+  HandlerFunction f = std::bind(&WebServer::apiWrapper, this, handler, std::placeholders::_1, std::placeholders::_2, allowPassword);
   registerBareHandler(url, f);
 }
 
@@ -196,7 +196,7 @@ void WebServer::webWrapper(WebServer::Ha
 }
 
 void WebServer::registerWebHandler(const string& url, HandlerFunction handler) {
-  HandlerFunction f = boost::bind(&WebServer::webWrapper, this, handler, _1, _2);
+  HandlerFunction f = std::bind(&WebServer::webWrapper, this, handler, std::placeholders::_1, std::placeholders::_2);
   registerBareHandler(url, f);
 }
 
