$NetBSD: patch-src_server_campaignd_server.cpp,v 1.1 2025/01/25 22:58:22 adam Exp $

Fix build with boost >= 1.87.0
https://github.com/wesnoth/wesnoth/pull/9653

--- src/server/campaignd/server.cpp.orig	2025-01-25 22:33:31.575682044 +0000
+++ src/server/campaignd/server.cpp
@@ -735,7 +735,7 @@ void server::handle_sighup(const boost::

 void server::flush_cfg()
 {
-	flush_timer_.expires_from_now(std::chrono::minutes(10));
+	flush_timer_.expires_after(std::chrono::minutes(10));
 	flush_timer_.async_wait(std::bind(&server::handle_flush, this, std::placeholders::_1));
 }
