$NetBSD: patch-source_blender_editors_screen_screen__ops.cc,v 1.1 2026/11/08 16:15:19 ryoon Exp $

--- source/blender/editors/screen/screen_ops.cc.orig	2026-09-13 15:53:52.868300545 +0000
+++ source/blender/editors/screen/screen_ops.cc
@@ -6461,7 +6461,7 @@ static wmOperatorStatus screen_animation_step_invoke(b
      * dependency graph update. */
   }
   else if ((scene->audio.flag & AUDIO_SYNC) && (sad->flag & ANIMPLAY_FLAG_REVERSE) == false &&
-           isfinite(time = BKE_sound_sync_scene(scene_eval)))
+           std::isfinite(time = BKE_sound_sync_scene(scene_eval)))
   {
     scene->r.cfra = round(time * scene->frames_per_second());
 
