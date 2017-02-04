$NetBSD: patch-solenv_gbuild_Module.mk,v 1.6 2017/02/04 01:48:00 ryoon Exp $

* Avoid endless tests

--- solenv/gbuild/Module.mk.orig	2017-01-26 22:22:46.000000000 +0000
+++ solenv/gbuild/Module.mk
@@ -142,7 +142,7 @@ $(call gb_Module_get_target,%) :
 .PHONY : all build build-l10n-only build-non-l10n-only unitcheck slowcheck screenshot subsequentcheck stagingcheck perfcheck uicheck clean check debugrun help showmodules translations
 .DEFAULT_GOAL := all
 
-all : build $(if $(CROSS_COMPILING),,unitcheck $(if $(gb_PARTIAL_BUILD),,slowcheck))
+all : build
 
 ifeq ($(gb_Side),build)
 build-tools : $(gb_BUILD_TOOLS)
