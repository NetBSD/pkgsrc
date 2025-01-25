$NetBSD: patch-src_server_common_server__base.hpp,v 1.1 2025/01/25 22:58:23 adam Exp $

Fix build with boost >= 1.87.0
https://github.com/wesnoth/wesnoth/pull/9653

--- src/server/common/server_base.hpp.orig	2025-01-25 22:41:27.055783416 +0000
+++ src/server/common/server_base.hpp
@@ -30,7 +30,7 @@
 #include "serialization/unicode_cast.hpp"
 #endif
 
-#include <boost/asio/io_service.hpp>
+#include <boost/asio/io_context.hpp>
 #include <boost/asio/ip/tcp.hpp>
 #ifndef _WIN32
 #include <boost/asio/posix/stream_descriptor.hpp>
@@ -150,7 +150,7 @@ public:
 protected:
 	unsigned short port_;
 	bool keep_alive_;
-	boost::asio::io_service io_service_;
+	boost::asio::io_context io_service_;
 	boost::asio::ssl::context tls_context_ { boost::asio::ssl::context::sslv23 };
 	bool tls_enabled_ { false };
 	boost::asio::ip::tcp::acceptor acceptor_v6_;
