$NetBSD: patch-include_woff2_output.h,v 1.1 2025/04/28 19:19:39 tnn Exp $

Include <cstdint> for uint8_t.

--- include/woff2/output.h.orig	2025-04-24 11:19:43.640292827 +0000
+++ include/woff2/output.h
@@ -11,6 +11,7 @@
 
 #include <algorithm>
 #include <cstring>
+#include <cstdint>
 #include <memory>
 #include <string>
 
