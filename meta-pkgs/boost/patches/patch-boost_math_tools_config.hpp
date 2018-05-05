$NetBSD: patch-boost_math_tools_config.hpp,v 1.6 2018/05/05 03:47:33 minskim Exp $

Enable 'long double' support on NetBSD.
NetBSD does not have int128_t, log1pl, etc.

--- boost/math/tools/config.hpp.orig	2018-04-11 13:49:04.000000000 +0000
+++ boost/math/tools/config.hpp
@@ -28,7 +28,7 @@
 
 #include <boost/math/tools/user.hpp>
 
-#if (defined(__CYGWIN__) || defined(__FreeBSD__) || defined(__NetBSD__) \
+#if (defined(__CYGWIN__) || defined(__FreeBSD__) \
    || (defined(__hppa) && !defined(__OpenBSD__)) || (defined(__NO_LONG_DOUBLE_MATH) && (DBL_MANT_DIG != LDBL_MANT_DIG))) \
    && !defined(BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS)
 #  define BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
@@ -103,7 +103,7 @@
 #  define BOOST_MATH_NO_DEDUCED_FUNCTION_POINTERS
 #endif
 
-#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901))
+#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)) && !defined(__NetBSD__)
 #  define BOOST_MATH_USE_C99
 #endif
 
@@ -267,7 +267,7 @@
 //
 // And then the actual configuration:
 //
-#if defined(_GLIBCXX_USE_FLOAT128) && defined(BOOST_GCC) && !defined(__STRICT_ANSI__) \
+#if (defined(_GLIBCXX_USE_FLOAT128) && !defined(__NetBSD__)) && defined(BOOST_GCC) && !defined(__STRICT_ANSI__) \
    && !defined(BOOST_MATH_DISABLE_FLOAT128) || defined(BOOST_MATH_USE_FLOAT128)
 //
 // Only enable this when the compiler really is GCC as clang and probably 
