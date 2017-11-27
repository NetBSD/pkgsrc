$NetBSD: patch-external_harfbuzz_UnpackedTarball__harfbuzz.mk,v 1.1 2017/11/27 23:59:24 ryoon Exp $

--- external/harfbuzz/UnpackedTarball_harfbuzz.mk.orig	2017-11-03 14:12:31.000000000 +0000
+++ external/harfbuzz/UnpackedTarball_harfbuzz.mk
@@ -15,7 +15,6 @@ $(eval $(call gb_UnpackedTarball_set_pat
 
 $(eval $(call gb_UnpackedTarball_add_patches,harfbuzz, \
     external/harfbuzz/clang-cl.patch \
-    external/harfbuzz/ubsan.patch \
 ))
 
 ifneq ($(ENABLE_RUNTIME_OPTIMIZATIONS),TRUE)
