$NetBSD: patch-src_server_wesnothd_game.cpp,v 1.1 2025/01/25 22:58:23 adam Exp $

Fix build with boost >= 1.87.0
https://github.com/wesnoth/wesnoth/pull/9653

--- src/server/wesnothd/game.cpp.orig	2025-01-25 22:43:20.211521144 +0000
+++ src/server/wesnothd/game.cpp
@@ -27,6 +27,8 @@
 #include <iomanip>
 #include <sstream>

+#include <boost/coroutine/exceptions.hpp>
+
 static lg::log_domain log_server("server");
 #define ERR_GAME LOG_STREAM(err, log_server)
 #define WRN_GAME LOG_STREAM(warn, log_server)
