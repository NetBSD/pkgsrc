$NetBSD: patch-source_blender_windowmanager_intern_wm__event__system.cc,v 1.1 2023/01/22 21:24:37 ryoon Exp $

--- source/blender/windowmanager/intern/wm_event_system.cc.orig	2022-11-15 17:58:40.000000000 +0000
+++ source/blender/windowmanager/intern/wm_event_system.cc
@@ -3841,7 +3841,7 @@ void wm_event_do_handlers(bContext *C)
 
           if (is_playing_sound == 0) {
             const double time = BKE_sound_sync_scene(scene_eval);
-            if (isfinite(time)) {
+            if (std::isfinite(time)) {
               int ncfra = round(time * FPS);
               if (ncfra != scene->r.cfra) {
                 scene->r.cfra = ncfra;
