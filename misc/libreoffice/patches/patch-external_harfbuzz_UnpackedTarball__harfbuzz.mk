$NetBSD: patch-external_harfbuzz_UnpackedTarball__harfbuzz.mk,v 1.7 2019/08/10 11:41:29 ryoon Exp $

--- external/harfbuzz/UnpackedTarball_harfbuzz.mk.orig	2019-08-06 17:26:35.000000000 +0000
+++ external/harfbuzz/UnpackedTarball_harfbuzz.mk
@@ -15,10 +15,4 @@ $(eval $(call gb_UnpackedTarball_update_
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,harfbuzz,0))
 
-# * external/harfbuzz/msvc.patch sent upstream as <https://github.com/harfbuzz/harfbuzz/pull/1605>
-#   "Fix hb_atomic_* variants based on C++11 atomics":
-$(eval $(call gb_UnpackedTarball_add_patches,harfbuzz, \
-    external/harfbuzz/msvc.patch \
-))
-
 # vim: set noet sw=4 ts=4:
