$NetBSD: patch-boost_config_stdlib_libcpp.hpp,v 1.1 2014/02/21 20:22:09 joerg Exp $

--- boost/config/stdlib/libcpp.hpp.orig	2014-02-21 00:34:58.000000000 +0000
+++ boost/config/stdlib/libcpp.hpp
@@ -33,5 +33,7 @@
 
 // libc++ uses a non-standard messages_base
 #define BOOST_NO_STD_MESSAGES
+// libc++ uses inline namespaces
+#define BOOST_DETAIL_NO_CONTAINER_FWD
 
 //  --- end ---
