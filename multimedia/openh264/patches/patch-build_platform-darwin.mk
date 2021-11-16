$NetBSD: patch-build_platform-darwin.mk,v 1.1 2021/11/16 14:56:36 nia Exp $

Remove stack protector, let pkgsrc apply it itself.

--- build/platform-darwin.mk.orig	2020-05-21 08:30:24.000000000 +0000
+++ build/platform-darwin.mk
@@ -10,7 +10,7 @@ SHLDFLAGS = -dynamiclib -twolevel_namesp
 	$(SHAREDLIB_DIR)/$(LIBPREFIX)$(PROJECT_NAME).$(SHAREDLIBSUFFIXMAJORVER)
 SHARED = -dynamiclib
 SHARED += -current_version $(CURRENT_VERSION) -compatibility_version $(COMPATIBILITY_VERSION)
-CFLAGS += -Wall -fPIC -MMD -MP -fstack-protector-all
+CFLAGS += -Wall -fPIC -MMD -MP
 ifeq ($(ASM_ARCH), x86)
 ASMFLAGS += -DPREFIX
 ifeq ($(ARCH), x86_64)
