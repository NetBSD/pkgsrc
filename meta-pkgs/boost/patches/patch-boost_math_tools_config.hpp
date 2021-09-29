$NetBSD: patch-boost_math_tools_config.hpp,v 1.8 2021/09/29 16:11:04 adam Exp $

Enable 'long double' support on NetBSD.
NetBSD does not have int128_t, log1pl, etc.

--- boost/math/tools/config.hpp.orig	2021-08-05 09:42:10.000000000 +0000
+++ boost/math/tools/config.hpp
@@ -155,7 +155,7 @@
 #  define BOOST_MATH_NO_DEDUCED_FUNCTION_POINTERS
 #endif
 
-#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901))
+#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)) && !defined(__NetBSD__)
 #  define BOOST_MATH_USE_C99
 #endif
 
@@ -304,6 +304,7 @@ struct non_type {};
 // And then the actual configuration:
 //
 #if defined(BOOST_MATH_STANDALONE) && defined(_GLIBCXX_USE_FLOAT128) && defined(__GNUC__) && defined(__GNUC_MINOR__) && defined(__GNUC_PATCHLEVEL__) && !defined(__STRICT_ANSI__) \
+   && !defined(__NetBSD__) \
    && !defined(BOOST_MATH_DISABLE_FLOAT128) && !defined(BOOST_MATH_USE_FLOAT128)
 #  define BOOST_MATH_USE_FLOAT128
 #elif defined(BOOST_HAS_FLOAT128) && !defined(BOOST_MATH_USE_FLOAT128)
