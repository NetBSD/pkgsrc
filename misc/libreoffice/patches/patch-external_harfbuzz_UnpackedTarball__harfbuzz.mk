$NetBSD: patch-external_harfbuzz_UnpackedTarball__harfbuzz.mk,v 1.5 2018/12/13 16:34:10 abs Exp $

--- external/harfbuzz/UnpackedTarball_harfbuzz.mk.orig	2018-10-29 19:55:29.000000000 +0000
+++ external/harfbuzz/UnpackedTarball_harfbuzz.mk
@@ -16,8 +16,7 @@ $(eval $(call gb_UnpackedTarball_update_
 $(eval $(call gb_UnpackedTarball_set_patchlevel,harfbuzz,0))
 
 $(eval $(call gb_UnpackedTarball_add_patches,harfbuzz, \
-    external/harfbuzz/clang-cl.patch \
-    external/harfbuzz/ubsan.patch \
+    external/harfbuzz/src-hb.patch \
 ))
 
 ifneq ($(ENABLE_RUNTIME_OPTIMIZATIONS),TRUE)
