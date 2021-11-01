$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.5 2021/11/01 14:06:49 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2021-10-06 00:34:15.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -41,6 +41,7 @@ skia_patches := \
     fix-warnings.patch.1 \
     disable-freetype-colrv1.1 \
     windows-libraries-system32.patch.1 \
+    netbsd.patch.0
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
