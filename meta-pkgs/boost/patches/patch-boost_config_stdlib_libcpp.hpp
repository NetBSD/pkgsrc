$NetBSD: patch-boost_config_stdlib_libcpp.hpp,v 1.4 2016/10/07 17:51:11 adam Exp $

--- boost/config/stdlib/libcpp.hpp.orig	2016-10-05 08:52:16.000000000 +0000
+++ boost/config/stdlib/libcpp.hpp
@@ -74,6 +74,8 @@
 // libc++ uses a non-standard messages_base
 #define BOOST_NO_STD_MESSAGES
 #endif
+// libc++ uses inline namespaces
+#define BOOST_DETAIL_NO_CONTAINER_FWD
 
 #if (_LIBCPP_VERSION <= 1101) && !defined(BOOST_NO_CXX11_THREAD_LOCAL)
 // This is a bit of a sledgehammer, because really it's just libc++abi that has no
