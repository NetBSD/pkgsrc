$NetBSD: patch-src_server_wesnothd_server.cpp,v 1.1 2025/01/25 22:58:23 adam Exp $

Fix build with boost >= 1.87.0
https://github.com/wesnoth/wesnoth/pull/9653

--- src/server/wesnothd/server.cpp.orig	2025-01-25 22:43:53.491385858 +0000
+++ src/server/wesnothd/server.cpp
@@ -293,14 +293,14 @@ void server::handle_graceful_timeout(con
 		process_command("msg All games ended. Shutting down now. Reconnect to the new server instance.", "system");
 		BOOST_THROW_EXCEPTION(server_shutdown("graceful shutdown timeout"));
 	} else {
-		timer_.expires_from_now(std::chrono::seconds(1));
+		timer_.expires_after(std::chrono::seconds(1));
 		timer_.async_wait(std::bind(&server::handle_graceful_timeout, this, std::placeholders::_1));
 	}
 }

 void server::start_lan_server_timer()
 {
-	lan_server_timer_.expires_from_now(std::chrono::seconds(lan_server_));
+	lan_server_timer_.expires_after(std::chrono::seconds(lan_server_));
 	lan_server_timer_.async_wait([this](const boost::system::error_code& ec) { handle_lan_server_shutdown(ec); });
 }

@@ -2120,7 +2120,7 @@ void server::shut_down_handler(
 		acceptor_v6_.close();
 		acceptor_v4_.close();

-		timer_.expires_from_now(std::chrono::seconds(10));
+		timer_.expires_after(std::chrono::seconds(10));
 		timer_.async_wait(std::bind(&server::handle_graceful_timeout, this, std::placeholders::_1));

 		process_command(
@@ -2151,7 +2151,7 @@ void server::restart_handler(const std::
 		graceful_restart = true;
 		acceptor_v6_.close();
 		acceptor_v4_.close();
-		timer_.expires_from_now(std::chrono::seconds(10));
+		timer_.expires_after(std::chrono::seconds(10));
 		timer_.async_wait(std::bind(&server::handle_graceful_timeout, this, std::placeholders::_1));

 		start_new_server();
