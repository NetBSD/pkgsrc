$NetBSD: patch-mozilla_gfx_skia_generate__mozbuild.py,v 1.1 2018/12/16 08:29:48 ryoon Exp $

--- mozilla/gfx/skia/generate_mozbuild.py.orig	2017-04-14 04:53:08.000000000 +0000
+++ mozilla/gfx/skia/generate_mozbuild.py
@@ -140,6 +140,9 @@ if CONFIG['CLANG_CXX'] or CONFIG['CLANG_
         '-Wno-unused-private-field',
     ]
 
+if CONFIG['MOZ_SYSTEM_HARFBUZZ']:
+    CXXFLAGS += CONFIG['MOZ_HARFBUZZ_CFLAGS']
+
 if CONFIG['MOZ_WIDGET_TOOLKIT'] in ('gtk2', 'gtk3', 'android'):
     CXXFLAGS += CONFIG['MOZ_CAIRO_CFLAGS']
     CXXFLAGS += CONFIG['CAIRO_FT_CFLAGS']
