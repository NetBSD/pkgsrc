$NetBSD: patch-boost_config_platform_solaris.hpp,v 1.1 2018/01/25 12:33:49 jperkin Exp $

Fix threading with clang.

--- boost/config/platform/solaris.hpp.orig	2018-01-25 11:41:29.424139830 +0000
+++ boost/config/platform/solaris.hpp
@@ -19,7 +19,7 @@
 //
 // pthreads don't actually work with gcc unless _PTHREADS is defined:
 //
-#if defined(__GNUC__) && defined(_POSIX_THREADS) && !defined(_PTHREADS)
+#if defined(__GNUC__) && !defined(__clang__) && defined(_POSIX_THREADS) && !defined(_PTHREADS)
 # undef BOOST_HAS_PTHREADS
 #endif
 
