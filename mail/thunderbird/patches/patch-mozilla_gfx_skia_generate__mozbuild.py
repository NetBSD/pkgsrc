$NetBSD: patch-mozilla_gfx_skia_generate__mozbuild.py,v 1.1 2015/07/09 15:17:34 ryoon Exp $

--- mozilla/gfx/skia/generate_mozbuild.py.orig	2015-06-08 17:49:16.000000000 +0000
+++ mozilla/gfx/skia/generate_mozbuild.py
@@ -142,6 +142,9 @@ if CONFIG['GNU_CXX']:
     if not CONFIG['CLANG_CXX']:
         CXXFLAGS += ['-Wno-logical-op']
 
+if CONFIG['MOZ_NATIVE_HARFBUZZ']:
+    CXXFLAGS += CONFIG['MOZ_HARFBUZZ_CFLAGS']
+
 if CONFIG['MOZ_WIDGET_TOOLKIT'] in ('gtk2', 'gtk3', 'android', 'gonk', 'qt'):
     CXXFLAGS += CONFIG['MOZ_CAIRO_CFLAGS']
     CXXFLAGS += CONFIG['CAIRO_FT_CFLAGS']
