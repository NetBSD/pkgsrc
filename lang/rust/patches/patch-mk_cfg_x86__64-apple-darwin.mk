$NetBSD: patch-mk_cfg_x86__64-apple-darwin.mk,v 1.1 2016/09/06 10:36:49 jperkin Exp $

Ensure we can use install_name_tool to fixup after.

--- mk/cfg/x86_64-apple-darwin.mk.orig	2016-08-16 01:54:35.000000000 +0000
+++ mk/cfg/x86_64-apple-darwin.mk
@@ -13,7 +13,7 @@ CFG_GCCISH_CXXFLAGS_x86_64-apple-darwin 
 CFG_GCCISH_LINK_FLAGS_x86_64-apple-darwin := -dynamiclib -pthread  -framework CoreServices -m64
 CFG_GCCISH_DEF_FLAG_x86_64-apple-darwin := -Wl,-exported_symbols_list,
 CFG_LLC_FLAGS_x86_64-apple-darwin :=
-CFG_INSTALL_NAME_x86_64-apple-darwin = -Wl,-install_name,@rpath/$(1)
+CFG_INSTALL_NAME_x86_64-apple-darwin = -Wl,-install_name,@rpath/$(1) -Wl,-headerpad_max_install_names
 CFG_EXE_SUFFIX_x86_64-apple-darwin :=
 CFG_WINDOWSY_x86_64-apple-darwin :=
 CFG_UNIXY_x86_64-apple-darwin := 1
