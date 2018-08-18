$NetBSD: patch-external_harfbuzz_UnpackedTarball__harfbuzz.mk,v 1.4 2018/08/18 00:11:32 ryoon Exp $

--- external/harfbuzz/UnpackedTarball_harfbuzz.mk.orig	2018-08-02 19:54:54.000000000 +0000
+++ external/harfbuzz/UnpackedTarball_harfbuzz.mk
@@ -15,11 +15,6 @@ $(eval $(call gb_UnpackedTarball_update_
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,harfbuzz,0))
 
-$(eval $(call gb_UnpackedTarball_add_patches,harfbuzz, \
-    external/harfbuzz/clang-cl.patch \
-    external/harfbuzz/ubsan.patch \
-))
-
 ifneq ($(ENABLE_RUNTIME_OPTIMIZATIONS),TRUE)
 $(eval $(call gb_UnpackedTarball_add_patches,harfbuzz, \
     external/harfbuzz/harfbuzz-rtti.patch \
