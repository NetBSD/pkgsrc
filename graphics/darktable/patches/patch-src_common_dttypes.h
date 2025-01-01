$NetBSD: patch-src_common_dttypes.h,v 1.1 2025/01/01 14:06:17 ryoon Exp $

--- src/common/dttypes.h.orig	2024-12-15 21:38:01.000000000 +0000
+++ src/common/dttypes.h
@@ -23,12 +23,14 @@
 //#define NO_COLORMATRIX_NAN
 
 #include <float.h>
-#include <math.h>
 
 // When included by a C++ file, restrict qualifiers are not allowed
 #ifdef __cplusplus
+#include <cmath>
 #define DT_RESTRICT
+using std::isfinite;
 #else
+#include <math.h>
 #define DT_RESTRICT restrict
 #endif
 
