$NetBSD: patch-external_harfbuzz_UnpackedTarball__harfbuzz.mk,v 1.8 2020/02/05 14:10:35 ryoon Exp $

--- external/harfbuzz/UnpackedTarball_harfbuzz.mk.orig	2020-01-22 23:14:16.000000000 +0000
+++ external/harfbuzz/UnpackedTarball_harfbuzz.mk
@@ -15,11 +15,4 @@ $(eval $(call gb_UnpackedTarball_update_
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,harfbuzz,0))
 
-# icu-65-api-macros-with-semicolon.patch.1
-#   See http://site.icu-project.org/download/65  Migration Issues
-$(eval $(call gb_UnpackedTarball_add_patches,harfbuzz, \
-    external/harfbuzz/ubsan.patch \
-    external/harfbuzz/icu-65-api-macros-with-semicolon.patch.1 \
-))
-
 # vim: set noet sw=4 ts=4:
