$NetBSD: patch-subprojects_xsf_include_xsf_amos_amos.h,v 1.1 2025/08/20 12:19:24 adam Exp $

Prefer C++ headers.

--- subprojects/xsf/include/xsf/amos/amos.h.orig	2025-04-26 00:49:42.000000000 +0000
+++ subprojects/xsf/include/xsf/amos/amos.h
@@ -94,8 +94,8 @@
 
 #include <stdlib.h>
 
-#include <complex.h>
-#include <math.h>
+#include <complex>
+#include <cmath>
 #include <memory> // unique_ptr
 
 namespace xsf {
