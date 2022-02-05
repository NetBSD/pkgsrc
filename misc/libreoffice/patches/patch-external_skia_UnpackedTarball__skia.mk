$NetBSD: patch-external_skia_UnpackedTarball__skia.mk,v 1.6 2022/02/05 04:53:43 ryoon Exp $

--- external/skia/UnpackedTarball_skia.mk.orig	2022-01-26 14:35:29.000000000 +0000
+++ external/skia/UnpackedTarball_skia.mk
@@ -37,6 +37,7 @@ skia_patches := \
     disable-freetype-colrv1.1 \
     windows-libraries-system32.patch.1 \
     fix-graphite-ifdef.patch.1 \
+    netbsd.patch.0
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
