$NetBSD: patch-source_blender_imbuf_intern_anim_movie.c,v 1.1 2021/07/26 05:15:15 mrg Exp $

Avoid a crash when playing mp4 files.

--- source/blender/imbuf/intern/anim_movie.c.orig	2021-05-01 19:00:25.000000000 -0700
+++ source/blender/imbuf/intern/anim_movie.c	2021-07-24 01:16:54.625074391 -0700
@@ -1262,7 +1262,7 @@ static void ffmpeg_seek_and_decode(struc
 
 static ImBuf *ffmpeg_fetchibuf(struct anim *anim, int position, IMB_Timecode_Type tc)
 {
-  if (anim == NULL) {
+  if (anim == NULL || anim->pFormatCtx == NULL) {
     return NULL;
   }
 
