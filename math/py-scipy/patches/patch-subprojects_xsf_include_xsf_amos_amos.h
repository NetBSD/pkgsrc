$NetBSD: patch-subprojects_xsf_include_xsf_amos_amos.h,v 1.2 2025/10/30 14:58:40 adam Exp $

Prefer C++ headers.

--- subprojects/xsf/include/xsf/amos/amos.h.orig	2025-10-10 18:07:54.000000000 +0000
+++ subprojects/xsf/include/xsf/amos/amos.h
@@ -95,7 +95,7 @@
 #include <stdlib.h>
 
 #include <complex>
-#include <math.h>
+#include <cmath>
 #include <memory> // unique_ptr
 
 namespace xsf {
