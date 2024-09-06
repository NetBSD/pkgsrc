$NetBSD: patch-source_blender_editors_screen_screen__ops.cc,v 1.1 2024/09/06 15:43:27 prlw1 Exp $

--- source/blender/editors/screen/screen_ops.cc.orig	2024-06-20 12:42:32.000000000 +0000
+++ source/blender/editors/screen/screen_ops.cc
@@ -4760,7 +4760,7 @@ static int screen_animation_step_invoke(
      * dependency graph update. */
   }
   else if ((scene->audio.flag & AUDIO_SYNC) && (sad->flag & ANIMPLAY_FLAG_REVERSE) == false &&
-           isfinite(time = BKE_sound_sync_scene(scene_eval)))
+           std::isfinite(time = BKE_sound_sync_scene(scene_eval)))
   {
     double newfra = time * FPS;
 
