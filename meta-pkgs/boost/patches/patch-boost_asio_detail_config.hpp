$NetBSD: patch-boost_asio_detail_config.hpp,v 1.1 2013/11/20 19:17:55 adam Exp $

GCC 4.5.x does not have std:addressof.

--- boost/asio/detail/config.hpp.orig	2013-11-20 17:59:30.000000000 +0000
+++ boost/asio/detail/config.hpp
@@ -333,11 +333,11 @@
 #   define BOOST_ASIO_HAS_STD_ADDRESSOF 1
 #  endif // defined(BOOST_ASIO_HAS_CLANG_LIBCXX)
 #  if defined(__GNUC__)
-#   if ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 5)) || (__GNUC__ > 4)
+#   if ((__GNUC__ == 4) && (__GNUC_MINOR__ > 5)) || (__GNUC__ > 4)
 #    if defined(__GXX_EXPERIMENTAL_CXX0X__)
 #     define BOOST_ASIO_HAS_STD_ADDRESSOF 1
 #    endif // defined(__GXX_EXPERIMENTAL_CXX0X__)
-#   endif // ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 5)) || (__GNUC__ > 4)
+#   endif // ((__GNUC__ == 4) && (__GNUC_MINOR__ > 5)) || (__GNUC__ > 4)
 #  endif // defined(__GNUC__)
 #  if defined(BOOST_ASIO_MSVC)
 #   if (_MSC_VER >= 1700)
