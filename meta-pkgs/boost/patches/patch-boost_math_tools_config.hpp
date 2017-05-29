$NetBSD: patch-boost_math_tools_config.hpp,v 1.4 2017/05/29 14:39:29 ryoon Exp $

* NetBSD has no int128_t
* NetBSD has no log1pl etc.

--- boost/math/tools/config.hpp.orig	2017-04-17 02:22:22.000000000 +0000
+++ boost/math/tools/config.hpp
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
