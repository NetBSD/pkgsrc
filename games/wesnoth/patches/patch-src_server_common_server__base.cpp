$NetBSD: patch-src_server_common_server__base.cpp,v 1.1 2025/01/25 22:58:23 adam Exp $

Fix build with boost >= 1.87.0
https://github.com/wesnoth/wesnoth/pull/9653

--- src/server/common/server_base.cpp.orig	2024-10-28 17:46:29.000000000 +0000
+++ src/server/common/server_base.cpp
@@ -43,6 +43,10 @@
 #endif
 #include <boost/asio/write.hpp>

+#ifndef BOOST_NO_EXCEPTIONS
+#include <boost/exception/diagnostic_information.hpp>
+#endif
+
 #include <array>
 #include <ctime>
 #include <functional>
