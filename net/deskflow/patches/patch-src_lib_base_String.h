$NetBSD: patch-src_lib_base_String.h,v 1.2 2025/05/30 21:17:32 tnn Exp $

cstdarg for va_list

--- src/lib/base/String.h.orig	2025-05-29 13:27:33.000000000 +0000
+++ src/lib/base/String.h
@@ -10,6 +10,7 @@
 
 #include "common/Common.h"
 
+#include <cstdarg>
 #include <string>
 
 namespace deskflow {
