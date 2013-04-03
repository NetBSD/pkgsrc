$NetBSD: patch-core_libs_dimg_filters_icc_iccmanager.h,v 1.2 2013/04/03 12:52:04 markd Exp $

--- core/libs/dimg/filters/icc/iccmanager.h.orig	2013-03-11 08:24:28.000000000 +0000
+++ core/libs/dimg/filters/icc/iccmanager.h
@@ -128,7 +128,7 @@ public:
     static void transformToSRGB(QImage& qimage, const IccProfile& inputProfile);
 
     /** Transforms the given QImage from sRGB to given display profile. */
-    static void transformForDisplay(QImage& qimage, const IccProfile& displayProfile1 = displayProfile());
+    static void transformForDisplay(QImage& qimage, const IccProfile& displayProfile1 = IccProfile());
 
 protected:
 
