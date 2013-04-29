$NetBSD: patch-unix_ibus_gen__mozc__xml.py,v 1.2 2013/04/29 09:21:24 ryoon Exp $

* Fix for pkgsrc installation.

--- unix/ibus/gen_mozc_xml.py.orig	2013-03-29 04:33:43.000000000 +0000
+++ unix/ibus/gen_mozc_xml.py
@@ -49,7 +49,7 @@ IBUS_COMPONENT_PROPS = {
     'description': '%s Component',
     # TODO(yusukes): Support Linux distributions other than Gentoo/ChromeOS.
     # For example, Ubuntu uses /usr/lib/ibus-mozc/.
-    'exec': '/usr/libexec/ibus-engine-mozc --ibus',
+    'exec': '@PREFIX@/libexec/ibus-engine-mozc --ibus',
     # TODO(mazda): Generate the version number.
     'version': '0.0.0.0',
     'author': 'Google Inc.',
@@ -62,7 +62,7 @@ IBUS_COMPONENT_PROPS = {
 IBUS_ENGINE_COMMON_PROPS = {
     'description': '%s (Japanese Input Method)',
     'language': 'ja',
-    'icon': '/usr/share/ibus-mozc/product_icon.png',
+    'icon': '@PREFIX@/share/ibus-mozc/product_icon.png',
     'rank': '80',
 }
 
@@ -95,6 +95,13 @@ IBUS_ENGINES_PROPS = {
         'longname': ['%s'],
         'layout': ['default'],
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
@@ -228,7 +235,15 @@ def main():
   platform = options.platform
   common_props = IBUS_ENGINE_COMMON_PROPS
   if platform == 'Linux':
-    setup_arg.append(os.path.join(options.server_dir, 'mozc_tool'))
+    setup_arg.append(os.path.join("@PREFIX@/libexec", 'mozc_tool'))
+    setup_arg.append('--mode=config_dialog')
+    if IsIBus15OrGreater(options):
+      # A tentative workaround against IBus 1.5
+      platform = 'Linux-IBus1.5'
+      common_props = IBUS_1_5_ENGINE_COMMON_PROPS
+
+  if platform == 'NetBSD':
+    setup_arg.append(os.path.join("@PREFIX@/libexec", 'mozc_tool'))
     setup_arg.append('--mode=config_dialog')
     if IsIBus15OrGreater(options):
       # A tentative workaround against IBus 1.5
