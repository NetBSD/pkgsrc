$NetBSD: patch-boost_config_stdlib_libcpp.hpp,v 1.2 2015/08/14 07:54:04 adam Exp $

--- boost/config/stdlib/libcpp.hpp.orig	2015-08-04 11:44:49.000000000 +0000
+++ boost/config/stdlib/libcpp.hpp
@@ -66,6 +66,8 @@
 
 // libc++ uses a non-standard messages_base
 #define BOOST_NO_STD_MESSAGES
+// libc++ uses inline namespaces
+#define BOOST_DETAIL_NO_CONTAINER_FWD
 
 #if defined(__has_include)
 #if !__has_include(<shared_mutex>)
