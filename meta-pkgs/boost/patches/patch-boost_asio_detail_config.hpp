$NetBSD: patch-boost_asio_detail_config.hpp,v 1.6 2018/04/30 00:21:12 ryoon Exp $

--- boost/asio/detail/config.hpp.orig	2018-04-11 13:49:00.000000000 +0000
+++ boost/asio/detail/config.hpp
@@ -811,7 +811,9 @@
 #  if defined(__GNUC__)
 #   if ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #    if (__cplusplus >= 201402)
+#    if __has_include(<experimental/string_view>)
 #     define BOOST_ASIO_HAS_STD_EXPERIMENTAL_STRING_VIEW 1
+#    endif // __has_include(<experimental/string_view>)
 #    endif // (__cplusplus >= 201402)
 #   endif // ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #  endif // defined(__GNUC__)
