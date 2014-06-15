$NetBSD: patch-unix_ibus_ibus.gyp,v 1.1 2014/06/15 13:08:34 ryoon Exp $

--- unix/ibus/ibus.gyp.orig	2014-05-21 10:49:56.000000000 +0000
+++ unix/ibus/ibus.gyp
@@ -31,8 +31,8 @@
   'variables': {
     'relative_dir': 'unix/ibus',
     'gen_out_dir': '<(SHARED_INTERMEDIATE_DIR)/<(relative_dir)',
-    'ibus_mozc_icon_path%': '/usr/share/ibus-mozc/product_icon.png',
-    'ibus_mozc_path%': '/usr/lib/ibus-mozc/ibus-engine-mozc',
+    'ibus_mozc_icon_path%': '@PREFIX@/share/ibus-mozc/product_icon.png',
+    'ibus_mozc_path%': '@PREFIX@/libexec/ibus-engine-mozc',
     # enable_x11_selection_monitor represents if ibus_mozc uses X11 selection
     # monitor or not.
     'enable_x11_selection_monitor%': 1,
