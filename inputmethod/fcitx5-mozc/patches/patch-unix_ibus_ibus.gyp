$NetBSD: patch-unix_ibus_ibus.gyp,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* use ${PREFIX} paths

--- unix/ibus/ibus.gyp.orig	2017-11-02 13:32:47.000000000 +0000
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
