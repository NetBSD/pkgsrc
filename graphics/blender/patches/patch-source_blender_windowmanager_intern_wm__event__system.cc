$NetBSD: patch-source_blender_windowmanager_intern_wm__event__system.cc,v 1.2 2024/09/06 15:43:28 prlw1 Exp $

--- source/blender/windowmanager/intern/wm_event_system.cc.orig	2024-06-05 11:47:57.000000000 +0000
+++ source/blender/windowmanager/intern/wm_event_system.cc
@@ -4022,7 +4022,7 @@ void wm_event_do_handlers(bContext *C)
 
           if (is_playing_sound == 0) {
             const double time = BKE_sound_sync_scene(scene_eval);
-            if (isfinite(time)) {
+            if (std::isfinite(time)) {
               int ncfra = round(time * FPS);
               if (ncfra != scene->r.cfra) {
                 scene->r.cfra = ncfra;
