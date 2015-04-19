$NetBSD: patch-boost_context_detail_config.hpp,v 1.2 2015/04/19 12:18:44 wiz Exp $

Fix build with gcc-4.8.4, which does not support index_sequence (from C++14).

--- boost/context/detail/config.hpp.orig	2015-04-04 17:31:00.000000000 +0000
+++ boost/context/detail/config.hpp
@@ -66,7 +66,8 @@
     defined( BOOST_NO_CXX11_RVALUE_REFERENCES) || \
     defined( BOOST_NO_CXX11_VARIADIC_MACROS) || \
     defined( BOOST_NO_CXX11_VARIADIC_TEMPLATES) || \
-    defined( BOOST_NO_CXX14_INITIALIZED_LAMBDA_CAPTURES) 
+    defined( BOOST_NO_CXX14_INITIALIZED_LAMBDA_CAPTURES) || \
+    (defined(__GNUC__) && __GNUC__ <= 4 && __GNUC_MINOR__ < 9)
 # define BOOST_CONTEXT_NO_EXECUTION_CONTEXT
 #endif
 
