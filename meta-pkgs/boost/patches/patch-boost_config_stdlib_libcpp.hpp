$NetBSD: patch-boost_config_stdlib_libcpp.hpp,v 1.3 2016/05/13 20:47:32 adam Exp $

--- boost/config/stdlib/libcpp.hpp.orig	2016-05-05 21:11:02.000000000 +0000
+++ boost/config/stdlib/libcpp.hpp
@@ -74,6 +74,8 @@
 // libc++ uses a non-standard messages_base
 #define BOOST_NO_STD_MESSAGES
 #endif
+// libc++ uses inline namespaces
+#define BOOST_DETAIL_NO_CONTAINER_FWD
 
 #if defined(__has_include)
 #if !__has_include(<shared_mutex>)
