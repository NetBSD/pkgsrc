$NetBSD: patch-gfx_skia_generate__mozbuild.py,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- gfx/skia/generate_mozbuild.py.orig	2014-11-21 03:37:30.000000000 +0000
+++ gfx/skia/generate_mozbuild.py
@@ -140,6 +140,9 @@ if CONFIG['GNU_CXX']:
     if not CONFIG['CLANG_CXX']:
         CXXFLAGS += ['-Wno-logical-op']
 
+if CONFIG['MOZ_NATIVE_HARFBUZZ']:
+    CXXFLAGS += CONFIG['MOZ_HARFBUZZ_CFLAGS']
+
 if CONFIG['MOZ_WIDGET_TOOLKIT'] in ('gtk2', 'gtk3', 'android', 'gonk', 'qt'):
     CXXFLAGS += CONFIG['MOZ_CAIRO_CFLAGS']
     CXXFLAGS += CONFIG['CAIRO_FT_CFLAGS']
