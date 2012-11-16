$NetBSD: patch-core_libs_dimg_filters_icc_iccmanager.h,v 1.1 2012/11/16 20:06:08 joerg Exp $

--- core/libs/dimg/filters/icc/iccmanager.h.orig	2012-11-16 18:20:53.000000000 +0000
+++ core/libs/dimg/filters/icc/iccmanager.h
@@ -129,7 +129,7 @@ public:
     static void transformToSRGB(QImage& qimage, const IccProfile& inputProfile);
 
     /** Transforms the given QImage from sRGB to given display profile. */
-    static void transformForDisplay(QImage& qimage, const IccProfile& displayProfile = displayProfile());
+    static void transformForDisplay(QImage& qimage, const IccProfile& displayProfile = IccProfile());
 
 protected:
 
