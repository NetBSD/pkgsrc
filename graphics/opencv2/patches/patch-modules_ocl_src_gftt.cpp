$NetBSD: patch-modules_ocl_src_gftt.cpp,v 1.1 2015/10/17 10:28:43 fhajny Exp $

Avoid GS define from sys/regset.h on SunOS.

--- modules/ocl/src/gftt.cpp.orig	2014-04-11 10:15:26.000000000 +0000
+++ modules/ocl/src/gftt.cpp
@@ -69,6 +69,9 @@ struct DefCornerCompare
     }
 };
 
+#if defined(__sun)
+#undef GS
+#endif
 // sort corner point using opencl bitonicosrt implementation
 static void sortCorners_caller(oclMat& corners, const int count)
 {
