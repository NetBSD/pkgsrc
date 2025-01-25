$NetBSD: patch-src_server_common_user__handler.hpp,v 1.1 2025/01/25 22:58:23 adam Exp $

Fix build with boost >= 1.87.0
https://github.com/wesnoth/wesnoth/pull/9653

--- src/server/common/user_handler.hpp.orig	2025-01-25 22:42:16.786148897 +0000
+++ src/server/common/user_handler.hpp
@@ -22,7 +22,7 @@ class config;
 #include <ctime>
 #include <string>
 
-#include <boost/asio/io_service.hpp>
+#include <boost/asio/io_context.hpp>
 
 #include "server/wesnothd/player_connection.hpp"
 
@@ -139,13 +139,13 @@ public:
 
 	virtual std::string get_uuid() = 0;
 	virtual std::string get_tournaments() = 0;
-	virtual void async_get_and_send_game_history(boost::asio::io_service& io_service, wesnothd::server& s, wesnothd::player_iterator player, int player_id, int offset, std::string& search_game_name, int search_content_type, std::string& search_content) =0;
+	virtual void async_get_and_send_game_history(boost::asio::io_context& io_service, wesnothd::server& s, wesnothd::player_iterator player, int player_id, int offset, std::string& search_game_name, int search_content_type, std::string& search_content) =0;
 	virtual void db_insert_game_info(const std::string& uuid, int game_id, const std::string& version, const std::string& name, int reload, int observers, int is_public, int has_password) = 0;
 	virtual void db_update_game_end(const std::string& uuid, int game_id, const std::string& replay_location) = 0;
 	virtual void db_insert_game_player_info(const std::string& uuid, int game_id, const std::string& username, int side_number, int is_host, const std::string& faction, const std::string& version, const std::string& source, const std::string& current_user, const std::string& leaders) = 0;
 	virtual unsigned long long db_insert_game_content_info(const std::string& uuid, int game_id, const std::string& type, const std::string& name, const std::string& id, const std::string& addon_id, const std::string& addon_version) = 0;
 	virtual void db_set_oos_flag(const std::string& uuid, int game_id) = 0;
-	virtual void async_test_query(boost::asio::io_service& io_service, int limit) = 0;
+	virtual void async_test_query(boost::asio::io_context& io_service, int limit) = 0;
 	virtual bool db_topic_id_exists(int topic_id) = 0;
 	virtual void db_insert_addon_info(const std::string& instance_version, const std::string& id, const std::string& name, const std::string& type, const std::string& version, bool forum_auth, int topic_id, const std::string uploader) = 0;
 	virtual unsigned long long db_insert_login(const std::string& username, const std::string& ip, const std::string& version) = 0;
