$NetBSD: patch-src_server_common_forum__user__handler.cpp,v 1.1 2025/01/25 22:58:22 adam Exp $

Fix build with boost >= 1.87.0
https://github.com/wesnoth/wesnoth/pull/9653

--- src/server/common/forum_user_handler.cpp.orig	2025-01-25 22:34:14.678468548 +0000
+++ src/server/common/forum_user_handler.cpp
@@ -207,7 +207,7 @@ std::string fuh::get_tournaments(){
 	return conn_.get_tournaments();
 }

-void fuh::async_get_and_send_game_history(boost::asio::io_service& io_service, wesnothd::server& s, wesnothd::player_iterator player, int player_id, int offset, std::string& search_game_name, int search_content_type, std::string& search_content) {
+void fuh::async_get_and_send_game_history(boost::asio::io_context& io_service, wesnothd::server& s, wesnothd::player_iterator player, int player_id, int offset, std::string& search_game_name, int search_content_type, std::string& search_content) {
 	boost::asio::post([this, &s, player, player_id, offset, &io_service, search_game_name, search_content_type, search_content] {
 		boost::asio::post(io_service, [player, &s, doc = conn_.get_game_history(player_id, offset, search_game_name, search_content_type, search_content)]{
 			s.send_to_player(player, *doc);
@@ -235,7 +235,7 @@ void fuh::db_set_oos_flag(const std::str
 	conn_.set_oos_flag(uuid, game_id);
 }

-void fuh::async_test_query(boost::asio::io_service& io_service, int limit) {
+void fuh::async_test_query(boost::asio::io_context& io_service, int limit) {
 	boost::asio::post([this, limit, &io_service] {
 		ERR_UH << "async test query starts!";
 		int i = conn_.async_test_query(limit);
