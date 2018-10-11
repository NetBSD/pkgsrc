$NetBSD: patch-3rdparty_genie_build_gmake.darwin_genie.make,v 1.1 2018/10/11 08:20:54 adam Exp $

Do not set optimization level, nor minimal macOS version.

--- 3rdparty/genie/build/gmake.darwin/genie.make.orig	2018-10-10 17:27:27.000000000 +0000
+++ 3rdparty/genie/build/gmake.darwin/genie.make
@@ -50,13 +50,13 @@ ifeq ($(config),release)
   INCLUDES           += -I"../../src/host/lua-5.3.0/src"
   INCLUDES           +=
   ALL_CPPFLAGS       += $(CPPFLAGS) -MMD -MP -MP $(DEFINES) $(INCLUDES)
-  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os -mmacosx-version-min=10.4
-  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os -mmacosx-version-min=10.4
-  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os -mmacosx-version-min=10.4
-  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os -mmacosx-version-min=10.4
-  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra -Os -mmacosx-version-min=10.4
+  ALL_ASMFLAGS       += $(ASMFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra
+  ALL_CFLAGS         += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra
+  ALL_CXXFLAGS       += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra
+  ALL_OBJCFLAGS      += $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra
+  ALL_OBJCPPFLAGS    += $(CXXFLAGS) $(CFLAGS) $(ALL_CPPFLAGS) $(ARCH) -Wall -Wextra
   ALL_RESFLAGS       += $(RESFLAGS) $(DEFINES) $(INCLUDES)
-  ALL_LDFLAGS        += $(LDFLAGS) -L. -mmacosx-version-min=10.4
+  ALL_LDFLAGS        += $(LDFLAGS) -L.
   LDDEPS             +=
   LIBS               += $(LDDEPS) -framework CoreServices
   EXTERNAL_LIBS      +=
