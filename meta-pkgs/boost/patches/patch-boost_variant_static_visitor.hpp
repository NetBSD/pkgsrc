$NetBSD: patch-boost_variant_static_visitor.hpp,v 1.1 2014/08/17 00:10:11 markd Exp $

Fix build with gcc 4.5.X
https://github.com/boostorg/variant/commit/8f111d3126c5a706f0eca0b90f5e01c9a4601178

--- boost/variant/static_visitor.hpp.orig	2014-08-16 23:31:01.000000000 +0000
+++ boost/variant/static_visitor.hpp
@@ -48,7 +48,7 @@ public: // typedefs
     typedef R result_type;
 
 protected: // for use as base class only
-#ifndef BOOST_NO_DEFAULTED_FUNCTIONS
+#if !defined(BOOST_NO_CXX11_DEFAULTED_FUNCTIONS) && !defined(BOOST_NO_CXX11_NON_PUBLIC_DEFAULTED_FUNCTIONS)
     static_visitor() = default;
     ~static_visitor() = default;
 #else
