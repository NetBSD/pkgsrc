$NetBSD: patch-solenv_gbuild_Module.mk,v 1.5 2016/02/11 09:45:27 ryoon Exp $

--- solenv/gbuild/Module.mk.orig	2016-01-27 00:58:25.000000000 +0000
+++ solenv/gbuild/Module.mk
@@ -122,7 +122,7 @@ $(call gb_Module_get_target,%) :
 .PHONY : all build build-l10n-only build-non-l10n-only unitcheck slowcheck subsequentcheck stagingcheck perfcheck clean check debugrun help showmodules translations
 .DEFAULT_GOAL := all
 
-all : build $(if $(CROSS_COMPILING),,unitcheck $(if $(gb_PARTIAL_BUILD),,slowcheck))
+all : build
 
 build-tools : $(gb_BUILD_TOOLS)
 	$(call gb_Output_announce,loaded tools: $(gb_BUILD_TOOLS),$(true),ALL,6)
