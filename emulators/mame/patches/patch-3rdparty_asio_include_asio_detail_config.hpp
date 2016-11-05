$NetBSD: patch-3rdparty_asio_include_asio_detail_config.hpp,v 1.1 2016/11/05 10:05:26 wiz Exp $

gcc coming with NetBSD does not provide string_view.

--- 3rdparty/asio/include/asio/detail/config.hpp.orig	2016-10-25 23:47:23.000000000 +0000
+++ 3rdparty/asio/include/asio/detail/config.hpp
@@ -714,7 +714,7 @@
 #    endif // __has_include(<experimental/string_view>)
 #   endif // (__cplusplus >= 201103)
 #  endif // defined(__clang__)
-#  if defined(__GNUC__)
+#  if defined(__GNUC__) && !defined(__NetBSD__)
 #   if ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #    if (__cplusplus >= 201300)
 #     define ASIO_HAS_STD_STRING_VIEW 1
