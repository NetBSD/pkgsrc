$NetBSD: patch-3rdparty_genie_build_gmake.darwin_genie.make,v 1.4 2026/06/07 21:09:35 wiz Exp $

Do not set minimal macOS version.

--- 3rdparty/genie/build/gmake.darwin/genie.make.orig	2026-05-27 19:03:56.000000000 +0000
+++ 3rdparty/genie/build/gmake.darwin/genie.make
@@ -53,13 +53,13 @@ ifeq ($(config),release)
   DEFINES            += -DNDEBUG -DLUA_COMPAT_MODULE -DLUA_USE_MACOSX
   INCLUDES           += -I"../../src/host/lua-5.3.0/src"
   ALL_CPPFLAGS       += $(CPPFLAGS) -MMD -MP -MP $(DEFINES) $(INCLUDES)
-  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM) -mmacosx-version-min=11.0
-  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM) -mmacosx-version-min=11.0
-  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM) -mmacosx-version-min=11.0
-  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM) -mmacosx-version-min=11.0
-  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM) -mmacosx-version-min=11.0
+  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM)
+  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM)
+  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM)
+  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM)
+  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM)
   ALL_RESFLAGS       += $(RESFLAGS) $(DEFINES) $(INCLUDES)
-  ALL_LDFLAGS        += $(LDFLAGS) -L"." -mmacosx-version-min=11.0
+  ALL_LDFLAGS        += $(LDFLAGS) -L"."
   LIBDEPS            +=
   LDDEPS             +=
   LDRESP              =
