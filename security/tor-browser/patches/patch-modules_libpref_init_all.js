$NetBSD: patch-modules_libpref_init_all.js,v 1.1 2017/01/22 12:27:22 ryoon Exp $

* Improve stability under NetBSD.

--- modules/libpref/init/all.js.orig	2015-10-29 22:17:56.000000000 +0000
+++ modules/libpref/init/all.js
@@ -4283,7 +4283,7 @@ pref("layers.max-active", -1);
 pref("layers.tiles.adjust", true);
 
 // Set the default values, and then override per-platform as needed
-pref("layers.offmainthreadcomposition.enabled", true);
+pref("layers.offmainthreadcomposition.enabled", false);
 // Compositor target frame rate. NOTE: If vsync is enabled the compositor
 // frame rate will still be capped.
 // -1 -> default (match layout.frame_rate or 60 FPS)
