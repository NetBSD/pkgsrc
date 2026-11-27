$NetBSD: patch-source_blender_editors_screen_screen__ops.cc,v 1.1 2026/11/27 13:46:28 adam Exp $

--- source/blender/editors/screen/screen_ops.cc.orig	2025-03-11 00:27:08.000000000 +0000
+++ source/blender/editors/screen/screen_ops.cc
@@ -5446,7 +5446,7 @@ static int screen_animation_step_invoke(bContext *C, w
      * dependency graph update. */
   }
   else if ((scene->audio.flag & AUDIO_SYNC) && (sad->flag & ANIMPLAY_FLAG_REVERSE) == false &&
-           isfinite(time = BKE_sound_sync_scene(scene_eval)))
+           std::isfinite(time = BKE_sound_sync_scene(scene_eval)))
   {
     scene->r.cfra = round(time * FPS);
 
