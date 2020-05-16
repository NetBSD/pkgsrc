$NetBSD: patch-pdns_ws-auth.cc,v 1.1 2020/05/16 02:14:47 joerg Exp $

--- pdns/ws-auth.cc.orig	2020-05-14 23:22:34.214926173 +0000
+++ pdns/ws-auth.cc
@@ -2297,8 +2297,8 @@ void AuthWebServer::webThread()
       d_ws->registerApiHandler("/api", &apiDiscovery);
     }
     if (::arg().mustDo("webserver")) {
-      d_ws->registerWebHandler("/style.css", boost::bind(&AuthWebServer::cssfunction, this, _1, _2));
-      d_ws->registerWebHandler("/", boost::bind(&AuthWebServer::indexfunction, this, _1, _2));
+      d_ws->registerWebHandler("/style.css", boost::bind(&AuthWebServer::cssfunction, this, boost::placeholders::_1, boost::placeholders::_2));
+      d_ws->registerWebHandler("/", boost::bind(&AuthWebServer::indexfunction, this, boost::placeholders::_1, boost::placeholders::_2));
     }
     d_ws->go();
   }
