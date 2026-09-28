$NetBSD: patch-solenv_gbuild_UnpackedTarball.mk,v 1.1 2026/09/28 19:25:59 tnn Exp $

The version target needs a dependency on the directory it writes to.
Failed at MAKE_JOBS=32 without this fix.

--- solenv/gbuild/UnpackedTarball.mk.orig	2026-09-28 16:57:47.260092702 +0000
+++ solenv/gbuild/UnpackedTarball.mk
@@ -210,6 +210,7 @@ $(call gb_UnpackedTarball_get_preparation_target,$(1))
 $(call gb_UnpackedTarball_get_preparation_target,$(1)) : $(gb_Module_CURRENTMAKEFILE) \
 	$(call gb_UnpackedTarball_get_version_target,$(1))
 $(call gb_UnpackedTarball_get_preparation_target,$(1)) :| $(dir $(call gb_UnpackedTarball_get_target,$(1))).dir
+$(call gb_UnpackedTarball_get_version_target,$(1)) :| $(dir $(call gb_UnpackedTarball_get_target,$(1))).dir
 $(call gb_UnpackedTarball_get_target,$(1)) :| $(dir $(call gb_UnpackedTarball_get_target,$(1))).dir
 $(call gb_UnpackedTarball_get_final_target,$(1)) : $(call gb_UnpackedTarball_get_target,$(1))
 
