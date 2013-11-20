$NetBSD: patch-boost_math_tools_config.hpp,v 1.1 2013/11/20 19:17:55 adam Exp $

Enable long double math functions on FreeBSD and NetBSD.

--- boost/math/tools/config.hpp.orig	2013-11-20 18:40:34.000000000 +0000
+++ boost/math/tools/config.hpp
@@ -23,7 +23,7 @@
 
 #include <boost/math/tools/user.hpp>
 
-#if (defined(__CYGWIN__) || defined(__FreeBSD__) || defined(__NetBSD__) \
+#if (defined(__CYGWIN__) \
    || (defined(__hppa) && !defined(__OpenBSD__)) || (defined(__NO_LONG_DOUBLE_MATH) && (DBL_MANT_DIG != LDBL_MANT_DIG))) \
    && !defined(BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS)
 #  define BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
