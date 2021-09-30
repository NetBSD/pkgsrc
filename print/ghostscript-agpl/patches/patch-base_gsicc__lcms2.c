$NetBSD: patch-base_gsicc__lcms2.c,v 1.1 2021/09/30 23:48:51 ryoon Exp $

* Fix typo in function name to fix link.

--- base/gsicc_lcms2.c.orig	2021-09-27 07:44:02.000000000 +0000
+++ base/gsicc_lcms2.c
@@ -462,7 +462,7 @@ int
 gscms_transform_color(gx_device *dev, gsicc_link_t *icclink, void *inputcolor,
                              void *outputcolor, int num_bytes)
 {
-    return gscms_transformm_color_const(dev, icclink, inputcolor, outputcolor, num_bytes);
+    return gscms_transform_color_const(dev, icclink, inputcolor, outputcolor, num_bytes);
 }
 
 int
