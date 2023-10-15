$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.10 2023/10/15 07:26:24 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2023-08-08 19:49:18.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -39,6 +39,7 @@ skia_patches := \
     tdf147342.patch.0 \
     redefinition-of-op.patch.0 \
     0001-Added-missing-include-cstdio.patch \
+    netbsd.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
