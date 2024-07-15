$NetBSD: patch-src_common_common.h,v 1.1 2024/07/15 09:33:09 adam Exp $

Fix build with fmtlib 11.

--- src/common/common.h.orig	2024-07-15 07:21:24.805961812 +0000
+++ src/common/common.h
@@ -35,6 +35,7 @@
 
 #include <fmt/format.h>
 #include <fmt/ostream.h>
+#include <fmt/ranges.h>
 
 #include <boost/algorithm/string.hpp>
 #include <boost/multiprecision/cpp_int.hpp>
