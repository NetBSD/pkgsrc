$NetBSD: patch-boost_asio_detail_config.hpp,v 1.7 2021/09/29 16:11:04 adam Exp $

--- boost/asio/detail/config.hpp.orig	2021-08-05 09:41:11.000000000 +0000
+++ boost/asio/detail/config.hpp
@@ -1153,7 +1153,9 @@
 #  elif defined(__GNUC__)
 #   if ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #    if (__cplusplus >= 201402)
+#    if __has_include(<experimental/string_view>)
 #     define BOOST_ASIO_HAS_STD_EXPERIMENTAL_STRING_VIEW 1
+#    endif // __has_include(<experimental/string_view>)
 #    endif // (__cplusplus >= 201402)
 #   endif // ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #  endif // defined(__GNUC__)
