$NetBSD: patch-unix_ibus_gen__mozc__xml.py,v 1.3 2013/09/07 18:42:14 ryoon Exp $

* Fix for pkgsrc installation.

--- unix/ibus/gen_mozc_xml.py.orig	2013-08-28 05:25:59.000000000 +0000
+++ unix/ibus/gen_mozc_xml.py
@@ -47,7 +47,7 @@ import sys
 IBUS_COMPONENT_PROPS = {
     'name': 'com.google.IBus.Mozc',
     'description': '%(product_name)s Component',
-    'exec': '%(ibus_mozc_path)s --ibus',
+    'exec': '@PREFIX@/libexec/ibus-engine-mozc --ibus',
     # TODO(mazda): Generate the version number.
     'version': '0.0.0.0',
     'author': 'Google Inc.',
@@ -60,7 +60,7 @@ IBUS_COMPONENT_PROPS = {
 IBUS_ENGINE_COMMON_PROPS = {
     'description': '%(product_name)s (Japanese Input Method)',
     'language': 'ja',
-    'icon': '%(ibus_mozc_icon_path)s',
+    'icon': '@PREFIX@/share/ibus-mozc/product_icon.png',
     'rank': '80',
 }
 
@@ -93,6 +93,22 @@ IBUS_ENGINES_PROPS = {
         'longname': ['%(product_name)s'],
         'layout': ['default'],
     },
+    'NetBSD': {
+        # DO NOT change the engine name 'mozc-jp'. The names is referenced by
+        # unix/ibus/mozc_engine.cc.
+        'name': ['mozc-jp'],
+        'longname': ['%(product_name)s'],
+        'layout': ['jp'],
+    },
+    # On NetBSD (IBus >= 1.5), we use special label 'default' for the keyboard
+    # layout.
+    'NetBSD-IBus1.5': {
+        # DO NOT change the engine name 'mozc-jp'. The names is referenced by
+        # unix/ibus/mozc_engine.cc.
+        'name': ['mozc-jp'],
+        'longname': ['%(product_name)s'],
+        'layout': ['default'],
+    },
     # On Chrome/Chromium OS, we provide three engines.
     'ChromeOS': {
         # DO NOT change the engine name 'mozc-jp'. The names is referenced by
@@ -225,13 +241,21 @@ def main():
   platform = options.platform
   common_props = IBUS_ENGINE_COMMON_PROPS
   if platform == 'Linux':
-    setup_arg.append(os.path.join(options.server_dir, 'mozc_tool'))
+    setup_arg.append(os.path.join("@PREFIX@/libexec", 'mozc_tool'))
     setup_arg.append('--mode=config_dialog')
     if IsIBus15OrGreater(options):
       # A tentative workaround against IBus 1.5
       platform = 'Linux-IBus1.5'
       common_props = IBUS_1_5_ENGINE_COMMON_PROPS
 
+  if platform == 'NetBSD':
+    setup_arg.append(os.path.join("@PREFIX@/libexec", 'mozc_tool'))
+    setup_arg.append('--mode=config_dialog')
+    if IsIBus15OrGreater(options):
+      # A tentative workaround against IBus 1.5
+      platform = 'NetBSD-IBus1.5'
+      common_props = IBUS_1_5_ENGINE_COMMON_PROPS
+
   param_dict = {'product_name': PRODUCT_NAMES[options.branding],
                 'ibus_mozc_path': options.ibus_mozc_path,
                 'ibus_mozc_icon_path': options.ibus_mozc_icon_path}
