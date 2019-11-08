$NetBSD: patch-3rdparty_genie_build_gmake.darwin_genie.make,v 1.3 2019/11/08 09:44:17 wiz Exp $

Do not set optimization level, nor minimal macOS version.

--- 3rdparty/genie/build/gmake.darwin/genie.make.orig	2019-10-29 17:16:37.000000000 +0000
+++ 3rdparty/genie/build/gmake.darwin/genie.make
@@ -49,13 +49,13 @@ ifeq ($(config),release)
   DEFINES            += -DNDEBUG -DLUA_COMPAT_MODULE -DLUA_USE_MACOSX
   INCLUDES           += -I"../../src/host/lua-5.3.0/src"
   ALL_CPPFLAGS       += $(CPPFLAGS) -MMD -MP -MP $(DEFINES) $(INCLUDES)
-  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM) -mmacosx-version-min=10.6
-  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM) -mmacosx-version-min=10.6
-  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM) -mmacosx-version-min=10.6
-  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM) -mmacosx-version-min=10.6
-  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM) -mmacosx-version-min=10.6
+  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM)
+  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM)
+  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM)
+  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM)
+  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os $(MPARAM)
   ALL_RESFLAGS       += $(RESFLAGS) $(DEFINES) $(INCLUDES)
-  ALL_LDFLAGS        += $(LDFLAGS) -L"." -mmacosx-version-min=10.6
+  ALL_LDFLAGS        += $(LDFLAGS) -L"."
   LIBDEPS            +=
   LDDEPS             +=
   LDRESP              =
