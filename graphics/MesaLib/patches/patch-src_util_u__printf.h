$NetBSD: patch-src_util_u__printf.h,v 1.1 2022/03/13 15:52:50 tnn Exp $

include cstdarg for va_list

--- src/util/u_printf.h.orig	2021-12-01 19:04:14.000000000 +0000
+++ src/util/u_printf.h
@@ -25,6 +25,7 @@
 #ifdef __cplusplus
 
 #include <string>
+#include <cstdarg>
 
 /* find next valid printf specifier in a C++ std::string */
 size_t util_printf_next_spec_pos(const std::string &s, size_t pos);
