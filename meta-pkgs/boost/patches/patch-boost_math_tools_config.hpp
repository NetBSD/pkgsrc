$NetBSD: patch-boost_math_tools_config.hpp,v 1.2 2015/12/28 13:52:18 ryoon Exp $

Enable long double math functions on FreeBSD and NetBSD.

--- boost/math/tools/config.hpp.orig	2015-12-11 18:00:52.000000000 +0000
+++ boost/math/tools/config.hpp
@@ -28,7 +28,7 @@
 
 #include <boost/math/tools/user.hpp>
 
-#if (defined(__CYGWIN__) || defined(__FreeBSD__) || defined(__NetBSD__) \
+#if (defined(__CYGWIN__) \
    || (defined(__hppa) && !defined(__OpenBSD__)) || (defined(__NO_LONG_DOUBLE_MATH) && (DBL_MANT_DIG != LDBL_MANT_DIG))) \
    && !defined(BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS)
 #  define BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
@@ -279,7 +279,7 @@
 //
 // And then the actual configuration:
 //
-#if defined(_GLIBCXX_USE_FLOAT128) && defined(BOOST_GCC) && !defined(__STRICT_ANSI__) \
+#if (defined(_GLIBCXX_USE_FLOAT128) && !defined(__NetBSD__)) && defined(BOOST_GCC) && !defined(__STRICT_ANSI__) \
    && !defined(BOOST_MATH_DISABLE_FLOAT128) || defined(BOOST_MATH_USE_FLOAT128)
 //
 // Only enable this when the compiler really is GCC as clang and probably 
