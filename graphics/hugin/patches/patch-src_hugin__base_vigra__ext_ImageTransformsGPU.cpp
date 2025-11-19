$NetBSD: patch-src_hugin__base_vigra__ext_ImageTransformsGPU.cpp,v 1.1 2025/11/19 16:00:48 adam Exp $

Already #included above.

--- src/hugin_base/vigra_ext/ImageTransformsGPU.cpp.orig	2025-11-19 06:40:55.321636979 +0000
+++ src/hugin_base/vigra_ext/ImageTransformsGPU.cpp
@@ -71,7 +71,6 @@ long getms()
 #include <time.h>
 
 #include <vector>
-#include <GL/glu.h>
 
 using std::cout;
 using std::cerr;
