$NetBSD: patch-boost_asio_detail_config.hpp,v 1.9 2026/02/26 10:21:00 wiz Exp $

1. chunk: ?
2. chunk: NetBSD has MSG_NOSIGNAL, even though _POSIX_VERSION is only 200112L
https://github.com/chriskohlhoff/asio/pull/1717

--- boost/asio/detail/config.hpp.orig	2025-12-03 13:46:38.000000000 +0000
+++ boost/asio/detail/config.hpp
@@ -521,7 +521,9 @@
 #  elif defined(__GNUC__)
 #   if ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #    if (__cplusplus >= 201402)
+#    if __has_include(<experimental/string_view>)
 #     define BOOST_ASIO_HAS_STD_EXPERIMENTAL_STRING_VIEW 1
+#    endif // __has_include(<experimental/string_view>)
 #    endif // (__cplusplus >= 201402)
 #   endif // ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #  endif // defined(__GNUC__)
@@ -1392,7 +1394,7 @@
 
 // Kernel support for MSG_NOSIGNAL.
 #if !defined(BOOST_ASIO_HAS_MSG_NOSIGNAL)
-# if defined(__linux__)
+# if defined(__linux__) || defined(__NetBSD__)
 #  define BOOST_ASIO_HAS_MSG_NOSIGNAL 1
 # elif defined(_POSIX_VERSION)
 #  if (_POSIX_VERSION >= 200809L)
