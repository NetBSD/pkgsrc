$NetBSD: patch-mozilla_gfx_skia_generate__mozbuild.py,v 1.1 2017/04/27 13:38:18 ryoon Exp $

--- mozilla/gfx/skia/generate_mozbuild.py.orig	2016-04-07 21:33:14.000000000 +0000
+++ mozilla/gfx/skia/generate_mozbuild.py
@@ -155,6 +155,12 @@ if CONFIG['GNU_CXX']:
     if CONFIG['CPU_ARCH'] == 'arm':
         SOURCES['skia/src/opts/SkBlitRow_opts_arm.cpp'].flags += ['-fomit-frame-pointer']
 
+if CONFIG['MOZ_NATIVE_HARFBUZZ']:
+    CXXFLAGS += CONFIG['MOZ_HARFBUZZ_CFLAGS']
+
+if CONFIG['MOZ_NATIVE_HARFBUZZ']:
+    CXXFLAGS += CONFIG['MOZ_HARFBUZZ_CFLAGS']
+
 if CONFIG['MOZ_WIDGET_TOOLKIT'] in ('gtk2', 'gtk3', 'android', 'gonk', 'qt'):
     CXXFLAGS += CONFIG['MOZ_CAIRO_CFLAGS']
     CXXFLAGS += CONFIG['CAIRO_FT_CFLAGS']
