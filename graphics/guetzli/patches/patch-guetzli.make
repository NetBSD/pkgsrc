$NetBSD: patch-guetzli.make,v 1.1 2020/04/12 08:41:02 adam Exp $

Don't override optimization flags.

--- guetzli.make.orig	2018-01-13 22:54:20.000000000 +0000
+++ guetzli.make
@@ -19,8 +19,8 @@ ifeq ($(config),release)
   INCLUDES += -I. -Ithird_party/butteraugli
   FORCE_INCLUDE +=
   ALL_CPPFLAGS += $(CPPFLAGS) -MMD -MP $(DEFINES) $(INCLUDES)
-  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) -O3 -g `pkg-config --cflags libpng`
-  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -O3 -g -std=c++11 `pkg-config --cflags libpng`
+  ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS) `pkg-config --cflags libpng`
+  ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS) -std=c++11 `pkg-config --cflags libpng`
   ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
   LIBS +=
   LDDEPS +=
