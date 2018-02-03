$NetBSD: patch-external_harfbuzz_UnpackedTarball__harfbuzz.mk,v 1.2 2018/02/03 00:39:50 ryoon Exp $

--- external/harfbuzz/UnpackedTarball_harfbuzz.mk.orig	2018-01-24 20:31:03.000000000 +0000
+++ external/harfbuzz/UnpackedTarball_harfbuzz.mk
@@ -17,8 +17,6 @@ $(eval $(call gb_UnpackedTarball_set_pat
 
 $(eval $(call gb_UnpackedTarball_add_patches,harfbuzz, \
     external/harfbuzz/clang-cl.patch \
-    external/harfbuzz/ubsan.patch \
-	external/harfbuzz/revert-make-inert.patch \
 ))
 
 ifneq ($(ENABLE_RUNTIME_OPTIMIZATIONS),TRUE)
