$NetBSD: patch-boost_asio_detail_config.hpp,v 1.4 2018/01/04 10:25:35 maya Exp $

Need C++17 for string view.

--- boost/asio/detail/config.hpp.orig	2017-12-13 23:56:41.000000000 +0000
+++ boost/asio/detail/config.hpp
@@ -782,8 +782,10 @@
 #  if defined(__GNUC__)
 #   if ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #    if (__cplusplus >= 201402)
+#if __cplusplus >= 201703L
 #     define BOOST_ASIO_HAS_STD_STRING_VIEW 1
 #     define BOOST_ASIO_HAS_STD_EXPERIMENTAL_STRING_VIEW 1
+#endif
 #    endif // (__cplusplus >= 201402)
 #   endif // ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 7)) || (__GNUC__ > 4)
 #  endif // defined(__GNUC__)
