$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.7 2022/08/22 13:58:32 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2022-08-10 14:14:32.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -38,6 +38,7 @@ skia_patches := \
     allow-no-es2restrictions.patch.1 \
     vk_mem_alloc.patch.1 \
     tdf148624.patch.1 \
+    netbsd.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
