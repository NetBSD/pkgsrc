$NetBSD: patch-src_server_common_forum__user__handler.hpp,v 1.1 2025/01/25 22:58:22 adam Exp $

Fix build with boost >= 1.87.0
https://github.com/wesnoth/wesnoth/pull/9653

--- src/server/common/forum_user_handler.hpp.orig	2024-10-28 17:46:29.000000000 +0000
+++ src/server/common/forum_user_handler.hpp
@@ -133,7 +133,7 @@ public:
 	 * @param search_content_type The content type to query for (ie: scenario)
 	 * @param search_content Query for games using this content ID. Supports leading and/or trailing wildcards.
 	 */
-	void async_get_and_send_game_history(boost::asio::io_service& io_service, wesnothd::server& s, wesnothd::player_iterator player, int player_id, int offset, std::string& search_game_name, int search_content_type, std::string& search_content);
+	void async_get_and_send_game_history(boost::asio::io_context& io_service, wesnothd::server& s, wesnothd::player_iterator player, int player_id, int offset, std::string& search_game_name, int search_content_type, std::string& search_content);

 	/**
 	 * Inserts game related information.
@@ -203,7 +203,7 @@ public:
 	 * @param io_service The boost io_service to use to post the query results back to the main boost::asio thread.
 	 * @param limit How many recursions to make in the query.
 	 */
-	void async_test_query(boost::asio::io_service& io_service, int limit);
+	void async_test_query(boost::asio::io_context& io_service, int limit);

 	/**
 	 * Checks whether a forum thread with @a topic_id exists.
