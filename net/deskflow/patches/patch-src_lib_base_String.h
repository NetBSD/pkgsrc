$NetBSD: patch-src_lib_base_String.h,v 1.4 2025/10/20 19:49:12 tnn Exp $

cstdarg for va_list

--- src/lib/base/String.h.orig	2025-09-11 14:59:52.000000000 +0000
+++ src/lib/base/String.h
@@ -8,6 +8,7 @@
 
 #pragma once
 
+#include <cstdarg>
 #include <string>
 
 //! std::string utilities
