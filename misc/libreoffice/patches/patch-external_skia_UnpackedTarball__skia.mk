$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.3 2021/02/06 06:47:24 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2021-01-27 19:33:49.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -36,7 +36,8 @@ skia_patches := \
     c++20.patch.0 \
     constexpr-debug-std-max.patch.1 \
     swap-buffers-rect.patch.1 \
-    ubsan.patch.0
+    ubsan.patch.0 \
+    netbsd.patch.0
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
