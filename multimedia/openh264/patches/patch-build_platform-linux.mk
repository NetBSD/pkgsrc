$NetBSD: patch-build_platform-linux.mk,v 1.1 2021/11/16 14:56:36 nia Exp $

Remove stack protector, let pkgsrc apply it itself.

--- build/platform-linux.mk.orig	2020-05-21 08:30:24.000000000 +0000
+++ build/platform-linux.mk
@@ -3,7 +3,7 @@ SHAREDLIBSUFFIX = so
 SHAREDLIBSUFFIXFULLVER=$(SHAREDLIBSUFFIX).$(FULL_VERSION)
 SHAREDLIBSUFFIXMAJORVER=$(SHAREDLIBSUFFIX).$(SHAREDLIB_MAJORVERSION)
 SHLDFLAGS = -Wl,-soname,$(LIBPREFIX)$(PROJECT_NAME).$(SHAREDLIBSUFFIXMAJORVER)
-CFLAGS += -Wall -fno-strict-aliasing -fPIC -MMD -MP -fstack-protector-all
+CFLAGS += -Wall -fno-strict-aliasing -fPIC -MMD -MP
 LDFLAGS += -lpthread
 STATIC_LDFLAGS += -lpthread -lm
 AR_OPTS = crD $@
