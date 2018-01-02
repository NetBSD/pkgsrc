$NetBSD: patch-boost_asio_detail_config.hpp,v 1.3 2018/01/02 06:39:49 ryoon Exp $

* NetBSD has no string_view header files

--- boost/asio/detail/config.hpp.orig	2017-12-13 23:56:41.000000000 +0000
+++ boost/asio/detail/config.hpp
@@ -782,8 +782,10 @@
 #  if defined(__GNUC__)
 #   if ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 9)) || (__GNUC__ > 4)
 #    if (__cplusplus >= 201402)
+#if !defined(__NetBSD__)
 #     define BOOST_ASIO_HAS_STD_STRING_VIEW 1
 #     define BOOST_ASIO_HAS_STD_EXPERIMENTAL_STRING_VIEW 1
+#endif
 #    endif // (__cplusplus >= 201402)
 #   endif // ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 7)) || (__GNUC__ > 4)
 #  endif // defined(__GNUC__)
