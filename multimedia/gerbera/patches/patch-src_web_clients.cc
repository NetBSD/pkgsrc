$NetBSD: patch-src_web_clients.cc,v 1.1 2026/01/03 10:28:11 wiz Exp $

Fix build with fmtlib 12.

--- src/web/clients.cc.orig	2026-01-03 10:10:41.591243145 +0000
+++ src/web/clients.cc
@@ -40,7 +40,7 @@
 
 static std::string secondsToString(const std::chrono::seconds& t)
 {
-    return fmt::format("{:%a %b %d %H:%M:%S %Y}", fmt::localtime(t.count()));
+    return grbLocaltime("{:%a %b %d %H:%M:%S %Y}", t);
 }
 
 void Web::Clients::process()
