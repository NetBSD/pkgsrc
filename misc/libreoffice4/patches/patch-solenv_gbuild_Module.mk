$NetBSD: patch-solenv_gbuild_Module.mk,v 1.2 2014/02/02 07:43:40 ryoon Exp $

* Disable never-ending test

--- solenv/gbuild/Module.mk.orig	2014-01-27 21:35:34.000000000 +0000
+++ solenv/gbuild/Module.mk
@@ -105,7 +105,7 @@ $(call gb_Module_get_target,%) :
 .PHONY : all build build-l10n-only build-non-l10n-only unitcheck slowcheck subsequentcheck clean check debugrun help showmodules translations
 .DEFAULT_GOAL := all
 
-all : build $(if $(CROSS_COMPILING),,unitcheck $(if $(gb_PARTIAL_BUILD),,slowcheck))
+all : build
 
 build-tools : $(gb_BUILD_TOOLS)
 	$(call gb_Output_announce,loaded tools: $(gb_BUILD_TOOLS),$(true),ALL,6)
