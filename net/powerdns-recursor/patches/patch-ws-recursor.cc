$NetBSD: patch-ws-recursor.cc,v 1.1 2020/06/17 22:55:11 otis Exp $

boost 1.73 moved placeholders into std::placeholders namespace
backport changes based on PR #9070 from
https://github.com/PowerDNS/pdns/pull/9070/

--- ws-recursor.cc.orig	2020-05-08 09:31:59.000000000 +0000
+++ ws-recursor.cc
@@ -512,7 +512,7 @@ RecursorWebServer::RecursorWebServer(FDM
   d_ws->bind();
 
   // legacy dispatch
-  d_ws->registerApiHandler("/jsonstat", boost::bind(&RecursorWebServer::jsonstat, this, _1, _2), true);
+  d_ws->registerApiHandler("/jsonstat", std::bind(&RecursorWebServer::jsonstat, this, std::placeholders::_1, std::placeholders::_2), true);
   d_ws->registerApiHandler("/api/v1/servers/localhost/cache/flush", &apiServerCacheFlush);
   d_ws->registerApiHandler("/api/v1/servers/localhost/config/allow-from", &apiServerConfigAllowFrom);
   d_ws->registerApiHandler("/api/v1/servers/localhost/config", &apiServerConfig);
@@ -743,5 +743,5 @@ void AsyncWebServer::go() {
   auto server = std::dynamic_pointer_cast<AsyncServer>(d_server);
   if (!server)
     return;
-  server->asyncWaitForConnections(d_fdm, boost::bind(&AsyncWebServer::serveConnection, this, _1));
+  server->asyncWaitForConnections(d_fdm, std::bind(&AsyncWebServer::serveConnection, this, std::placeholders::_1));
 }
