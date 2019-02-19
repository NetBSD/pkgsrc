$NetBSD: patch-external_harfbuzz_UnpackedTarball__harfbuzz.mk,v 1.6 2019/02/19 16:28:03 ryoon Exp $

--- external/harfbuzz/UnpackedTarball_harfbuzz.mk.orig	2019-01-23 19:35:25.000000000 +0000
+++ external/harfbuzz/UnpackedTarball_harfbuzz.mk
@@ -15,19 +15,10 @@ $(eval $(call gb_UnpackedTarball_update_
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,harfbuzz,0))
 
-$(eval $(call gb_UnpackedTarball_add_patches,harfbuzz, \
-    external/harfbuzz/clang-cl.patch \
-    external/harfbuzz/ubsan.patch \
-))
-
 ifneq ($(ENABLE_RUNTIME_OPTIMIZATIONS),TRUE)
 $(eval $(call gb_UnpackedTarball_add_patches,harfbuzz, \
     external/harfbuzz/harfbuzz-rtti.patch \
 ))
 endif
 
-$(eval $(call gb_UnpackedTarball_add_patches,harfbuzz, \
-    external/harfbuzz/harfbuzz-ios.patch \
-))
-
 # vim: set noet sw=4 ts=4:
