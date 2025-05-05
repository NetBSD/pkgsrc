$NetBSD: patch-src_lib_base_String.h,v 1.1 2025/05/05 08:39:56 tnn Exp $

cstdarg for va_list

--- src/lib/base/String.h.orig	2025-04-27 17:04:05.677655830 +0000
+++ src/lib/base/String.h
@@ -10,6 +10,7 @@
 
 #include "common/Common.h"
 
+#include <cstdarg>
 #include <string>
 #include <vector>
 
