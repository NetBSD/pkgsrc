$NetBSD: patch-boost_asio_detail_config.hpp,v 1.10 2026/05/15 09:13:49 adam Exp $

1. chunk: ?

--- boost/asio/detail/config.hpp.orig	2026-04-15 14:38:52.000000000 +0000
+++ boost/asio/detail/config.hpp
@@ -528,7 +528,9 @@
 #  elif defined(__GNUC__)
 #   if ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #    if (__cplusplus >= 201402)
+#    if __has_include(<experimental/string_view>)
 #     define BOOST_ASIO_HAS_STD_EXPERIMENTAL_STRING_VIEW 1
+#    endif // __has_include(<experimental/string_view>)
 #    endif // (__cplusplus >= 201402)
 #   endif // ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #  endif // defined(__GNUC__)
