$NetBSD: patch-boost_charconv_detail_config.hpp,v 1.2 2024/07/06 08:53:57 cheusov Exp $

--- boost/charconv/detail/config.hpp.orig	2024-04-18 00:33:06.932281929 +0000
+++ boost/charconv/detail/config.hpp
@@ -27,7 +27,7 @@
 #  define BOOST_CHARCONV_UINT128_MAX (2 * static_cast<boost::uint128_type>(BOOST_CHARCONV_INT128_MAX) + 1)
 #endif
 
-#if defined(BOOST_HAS_FLOAT128) && !defined(__STRICT_ANSI__) && !defined(BOOST_CHARCONV_NO_QUADMATH)
+#if defined(BOOST_HAS_FLOAT128) && !defined(__STRICT_ANSI__) && !defined(BOOST_CHARCONV_NO_QUADMATH) && !defined(__NetBSD__) && !defined(__GLIBC__)
 #  define BOOST_CHARCONV_HAS_FLOAT128
 #  include <quadmath.h>
 #endif
