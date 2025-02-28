$NetBSD: patch-boost_move_detail_std__ns__begin.hpp,v 1.2 2025/02/28 18:41:10 wiz Exp $

https://github.com/boostorg/move/commit/5f073f8f00ee23b4502c0ad30a3aa2a5154cd1e8

--- boost/move/detail/std_ns_begin.hpp.orig	2024-12-05 00:53:34.000000000 +0000
+++ boost/move/detail/std_ns_begin.hpp
@@ -9,6 +9,9 @@
 #//
 #//////////////////////////////////////////////////////////////////////////////
 #
+#ifndef BOOST_CONFIG_HPP
+#  include <boost/config.hpp>
+#endif
 #if defined(_LIBCPP_VERSION)
    #if defined(__clang__)
       #define BOOST_MOVE_STD_NS_GCC_DIAGNOSTIC_PUSH
@@ -26,6 +29,9 @@
 #elif defined(BOOST_DINKUMWARE_STDLIB)
    #define BOOST_MOVE_STD_NS_BEG _STD_BEGIN
    #define BOOST_MOVE_STD_NS_END _STD_END
+#else
+   #define BOOST_MOVE_STD_NS_BEG namespace std {
+   #define BOOST_MOVE_STD_NS_END }
 #endif
 
 #if defined(_MSC_VER) && (_MSC_VER >= 1915)
