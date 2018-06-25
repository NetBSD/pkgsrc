$NetBSD: patch-external_harfbuzz_UnpackedTarball__harfbuzz.mk,v 1.3 2018/06/25 13:34:48 ryoon Exp $

--- external/harfbuzz/UnpackedTarball_harfbuzz.mk.orig	2018-06-19 22:27:30.000000000 +0000
+++ external/harfbuzz/UnpackedTarball_harfbuzz.mk
@@ -15,12 +15,6 @@ $(eval $(call gb_UnpackedTarball_update_
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,harfbuzz,0))
 
-$(eval $(call gb_UnpackedTarball_add_patches,harfbuzz, \
-    external/harfbuzz/clang-cl.patch \
-    external/harfbuzz/ubsan.patch \
-	external/harfbuzz/revert-make-inert.patch \
-))
-
 ifneq ($(ENABLE_RUNTIME_OPTIMIZATIONS),TRUE)
 $(eval $(call gb_UnpackedTarball_add_patches,harfbuzz, \
     external/harfbuzz/harfbuzz-rtti.patch \
