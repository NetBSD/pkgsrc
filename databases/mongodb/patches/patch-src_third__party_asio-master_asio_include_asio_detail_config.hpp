$NetBSD: patch-src_third__party_asio-master_asio_include_asio_detail_config.hpp,v 1.1 2019/03/05 19:35:58 adam Exp $

experimental/string_view is deprecated.

--- src/third_party//asio-master/asio/include/asio/detail/config.hpp.orig	2019-03-04 18:53:19.000000000 +0000
+++ src/third_party//asio-master/asio/include/asio/detail/config.hpp
@@ -784,17 +784,15 @@
 # if !defined(ASIO_DISABLE_STD_STRING_VIEW)
 #  if defined(__clang__)
 #   if (__cplusplus >= 201402)
-#    if __has_include(<experimental/string_view>)
+#    if __has_include(<string_view>)
 #     define ASIO_HAS_STD_STRING_VIEW 1
-#     define ASIO_HAS_STD_EXPERIMENTAL_STRING_VIEW 1
-#    endif // __has_include(<experimental/string_view>)
+#    endif // __has_include(<string_view>)
 #   endif // (__cplusplus >= 201402)
 #  endif // defined(__clang__)
 #  if defined(__GNUC__)
 #   if ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #    if (__cplusplus >= 201402)
 #     define ASIO_HAS_STD_STRING_VIEW 1
-#     define ASIO_HAS_STD_EXPERIMENTAL_STRING_VIEW 1
 #    endif // (__cplusplus >= 201402)
 #   endif // ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 7)) || (__GNUC__ > 4)
 #  endif // defined(__GNUC__)
