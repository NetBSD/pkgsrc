$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.4 2021/08/22 02:41:50 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2021-08-16 19:56:28.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -39,6 +39,7 @@ skia_patches := \
     fast-png-write.patch.1 \
     skia_sk_cpu_sse_level_0_by_default.patch.1 \
     fix-warnings.patch.1 \
+    netbsd.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
