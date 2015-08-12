$NetBSD: patch-solenv_gbuild_Module.mk,v 1.4 2015/08/12 00:57:20 ryoon Exp $

* Disable never-ending test

--- solenv/gbuild/Module.mk.orig	2015-01-22 20:05:28.000000000 +0000
+++ solenv/gbuild/Module.mk
@@ -114,7 +114,7 @@ $(call gb_Module_get_target,%) :
 .PHONY : all build build-l10n-only build-non-l10n-only unitcheck slowcheck subsequentcheck perfcheck clean check debugrun help showmodules translations
 .DEFAULT_GOAL := all
 
-all : build $(if $(CROSS_COMPILING),,unitcheck $(if $(gb_PARTIAL_BUILD),,slowcheck))
+all : build
 
 build-tools : $(gb_BUILD_TOOLS)
 	$(call gb_Output_announce,loaded tools: $(gb_BUILD_TOOLS),$(true),ALL,6)
