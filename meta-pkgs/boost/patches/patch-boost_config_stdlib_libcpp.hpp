$NetBSD: patch-boost_config_stdlib_libcpp.hpp,v 1.5 2017/01/01 15:32:47 adam Exp $

--- boost/config/stdlib/libcpp.hpp.orig	2017-01-01 02:18:57.000000000 +0000
+++ boost/config/stdlib/libcpp.hpp
@@ -73,6 +73,8 @@
 #  define BOOST_NO_CXX11_HDR_FUTURE
 #endif
 
+// libc++ uses inline namespaces
+#define BOOST_DETAIL_NO_CONTAINER_FWD
 
 #if _LIBCPP_VERSION < 3700
 // libc++ uses a non-standard messages_base
