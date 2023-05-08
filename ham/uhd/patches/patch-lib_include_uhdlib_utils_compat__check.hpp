$NetBSD: patch-lib_include_uhdlib_utils_compat__check.hpp,v 1.2 2023/05/08 18:28:52 tnn Exp $

Complains about missing uint8_t with GCC 13 on Fedora 38.

--- lib/include/uhdlib/utils/compat_check.hpp.orig	2023-01-27 21:17:39.000000000 +0000
+++ lib/include/uhdlib/utils/compat_check.hpp
@@ -8,6 +8,7 @@
 
 #include <cstddef>
 #include <string>
+#include <cstdint>
 
 namespace uhd {
 
