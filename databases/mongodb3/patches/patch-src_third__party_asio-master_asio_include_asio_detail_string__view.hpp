$NetBSD: patch-src_third__party_asio-master_asio_include_asio_detail_string__view.hpp,v 1.1 2024/08/04 10:11:11 nia Exp $

Work around a bug in NetBSD 9 and prior where GCC was shipped without
the experimental headers.

--- src/third_party/asio-master/asio/include/asio/detail/string_view.hpp.orig	2024-08-04 10:09:11.263644509 +0000
+++ src/third_party/asio-master/asio/include/asio/detail/string_view.hpp
@@ -19,7 +19,7 @@
 
 #if defined(ASIO_HAS_STD_STRING_VIEW)
 
-#if defined(ASIO_HAS_STD_EXPERIMENTAL_STRING_VIEW)
+#if defined(ASIO_HAS_STD_EXPERIMENTAL_STRING_VIEW) && !defined(__NetBSD__)
 # include <experimental/string_view>
 #else // defined(ASIO_HAS_EXPERIMENTAL_STRING_VIEW)
 # include <string_view>
