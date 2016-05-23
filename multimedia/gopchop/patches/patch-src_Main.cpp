$NetBSD: patch-src_Main.cpp,v 1.1.2.2 2016/05/23 05:04:39 bsiegert Exp $

C99 initializers are not valid in C++.

--- src/Main.cpp.orig	2016-05-06 18:19:50.000000000 +0000
+++ src/Main.cpp
@@ -124,19 +124,20 @@ int *client_pipe = NULL;
  * Update the menu activation handler to auto-save the rc file.
  */
 global_options options={
-    run_loop:             0, /* don't wrap arround by default */
-    run_speed:            1, /* one frame at a time by default */
-    default_run_speed:    1, /* one frame at a time by default */
-    auto_refresh:         1, /* show gop position changes by default */
-    ignore_errors:        0, /* don't ignore errors by default */
-    drop_orphaned_frames: 0, /* orphaned frame dropping can be nasty */
-    adjust_timestamps:    1, /* adjust by default */
-    video_driver_ptr:     NULL, /* prefered video driver */
-    video_driver:         "\0",
-    force_system_header:  0, /* force prepended system header pack */
-    drop_trailing_pack_with_system_header: 0, /* drop final pack if it has a system header */
-    ignore_endcode:       0, /* don't stop parsing when an End Code is seen */
+    /* run_loop: */             0, /* don't wrap arround by default */
+    /* run_speed: */            1, /* one frame at a time by default */
+    /* default_run_speed: */    1, /* one frame at a time by default */
+    /* auto_refresh: */         1, /* show gop position changes by default */
+    /* ignore_errors: */        0, /* don't ignore errors by default */
+    /* drop_orphaned_frames: */ 0, /* orphaned frame dropping can be nasty */
+    /* adjust_timestamps: */    1, /* adjust by default */
+    /* video_driver_ptr: */     NULL, /* prefered video driver */
+    /* video_driver: */         "\0",
+    /* force_system_header: */  0, /* force prepended system header pack */
+    /* drop_trailing_pack_with_system_header: */ 0, /* drop final pack if it has a system header */
+    /* ignore_endcode: */       0, /* don't stop parsing when an End Code is seen */
 };
+
 rc_parse_item parsable_items[] = {
     { "run_loop",             &options.run_loop,             RC_TYPE_BOOLEAN },
     { "default_run_speed",    &options.default_run_speed,    RC_TYPE_INTEGER },
