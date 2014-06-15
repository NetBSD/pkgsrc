$NetBSD: patch-unix_ibus_gen__mozc__xml.py,v 1.6 2014/06/15 13:08:34 ryoon Exp $

* Fix for pkgsrc installation.

--- unix/ibus/gen_mozc_xml.py.orig	2014-05-21 10:49:56.000000000 +0000
+++ unix/ibus/gen_mozc_xml.py
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
 }
 
 # A dictionary from --branding to a product name which is embedded into the
@@ -209,7 +225,7 @@ def main():
   (options, unused_args) = parser.parse_args()
 
   setup_arg = []
-  setup_arg.append(os.path.join(options.server_dir, 'mozc_tool'))
+  setup_arg.append(os.path.join("@PREFIX@/libexec", 'mozc_tool'))
   setup_arg.append('--mode=config_dialog')
   if IsIBus15OrGreater(options):
     # A tentative workaround against IBus 1.5
@@ -219,6 +235,14 @@ def main():
     platform = 'Linux'
     common_props = IBUS_ENGINE_COMMON_PROPS
 
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
