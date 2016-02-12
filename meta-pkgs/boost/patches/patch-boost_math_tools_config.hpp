$NetBSD: patch-boost_math_tools_config.hpp,v 1.3 2016/02/12 14:24:01 ryoon Exp $

* NetBSD has no int128_t

--- boost/math/tools/config.hpp.orig	2015-12-11 18:00:52.000000000 +0000
+++ boost/math/tools/config.hpp
@@ -279,7 +279,7 @@
 //
 // And then the actual configuration:
 //
-#if defined(_GLIBCXX_USE_FLOAT128) && defined(BOOST_GCC) && !defined(__STRICT_ANSI__) \
+#if (defined(_GLIBCXX_USE_FLOAT128) && !defined(__NetBSD__)) && defined(BOOST_GCC) && !defined(__STRICT_ANSI__) \
    && !defined(BOOST_MATH_DISABLE_FLOAT128) || defined(BOOST_MATH_USE_FLOAT128)
 //
 // Only enable this when the compiler really is GCC as clang and probably 
