$NetBSD: patch-unix_ibus_gen__mozc__xml.py,v 1.1 2013/01/18 11:36:40 ryoon Exp $

* Fix for pkgsrc installation.

--- unix/ibus/gen_mozc_xml.py.orig	2012-08-31 05:36:43.000000000 +0000
+++ unix/ibus/gen_mozc_xml.py
@@ -48,7 +48,7 @@ IBUS_COMPONENT_PROPS = {
     'description': '%s Component',
     # TODO(yusukes): Support Linux distributions other than Gentoo/ChromeOS.
     # For example, Ubuntu uses /usr/lib/ibus-mozc/.
-    'exec': '/usr/libexec/ibus-engine-mozc --ibus',
+    'exec': '@PREFIX@/libexec/ibus-engine-mozc --ibus',
     # TODO(mazda): Generate the version number.
     'version': '0.0.0.0',
     'author': 'Google Inc.',
@@ -61,7 +61,7 @@ IBUS_COMPONENT_PROPS = {
 IBUS_ENGINE_COMMON_PROPS = {
     'description': '%s (Japanese Input Method)',
     'language': 'ja',
-    'icon': '/usr/share/ibus-mozc/product_icon.png',
+    'icon': '@PREFIX@/share/ibus-mozc/product_icon.png',
     'rank': '80',
 }
 
@@ -76,6 +76,13 @@ IBUS_ENGINES_PROPS = {
         'longname': ['%s'],
         'layout': ['jp'],
     },
+    'NetBSD': {
+        # DO NOT change the engine name 'mozc-jp'. The names is referenced by
+        # unix/ibus/mozc_engine.cc.
+        'name': ['mozc-jp'],
+        'longname': ['%s'],
+        'layout': ['jp'],
+    },
     # On Chrome/Chromium OS, we provide three engines.
     'ChromeOS': {
         # DO NOT change the engine name 'mozc-jp'. The names is referenced by
@@ -193,7 +200,11 @@ def main():
 
   setup_arg = []
   if options.platform == 'Linux':
-    setup_arg.append(os.path.join(options.server_dir, 'mozc_tool'))
+    setup_arg.append(os.path.join("@PREFIX@/libexec", 'mozc_tool'))
+    setup_arg.append('--mode=config_dialog')
+
+  if options.platform == 'NetBSD':
+    setup_arg.append(os.path.join("@PREFIX@/libexec", 'mozc_tool'))
     setup_arg.append('--mode=config_dialog')
 
   if options.output_cpp:
