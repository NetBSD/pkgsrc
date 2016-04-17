$NetBSD: patch-mozilla_modules_libpref_init_all.js,v 1.1 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/modules/libpref/init/all.js.orig	2016-04-07 21:33:29.000000000 +0000
+++ mozilla/modules/libpref/init/all.js
@@ -4332,7 +4332,7 @@ pref("layers.max-active", -1);
 pref("layers.tiles.adjust", true);
 
 // Set the default values, and then override per-platform as needed
-pref("layers.offmainthreadcomposition.enabled", true);
+pref("layers.offmainthreadcomposition.enabled", false);
 // Compositor target frame rate. NOTE: If vsync is enabled the compositor
 // frame rate will still be capped.
 // -1 -> default (match layout.frame_rate or 60 FPS)
