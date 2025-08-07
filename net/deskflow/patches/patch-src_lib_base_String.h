$NetBSD: patch-src_lib_base_String.h,v 1.3 2025/08/07 13:59:30 abs Exp $

cstdarg for va_list

--- src/lib/base/String.h.orig	2025-07-23 13:27:06.000000000 +0000
+++ src/lib/base/String.h
@@ -10,6 +10,7 @@
 
 #include "common/Common.h"
 
+#include <cstdarg>
 #include <string>
 
 //! std::string utilities
