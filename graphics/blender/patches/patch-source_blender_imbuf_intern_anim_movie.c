$NetBSD: patch-source_blender_imbuf_intern_anim_movie.c,v 1.2 2023/10/15 19:53:20 ryoon Exp $

Avoid a crash when playing mp4 files.

--- source/blender/imbuf/intern/anim_movie.cc.orig	2023-06-19 18:45:48.000000000 +0000
+++ source/blender/imbuf/intern/anim_movie.cc
@@ -453,7 +453,7 @@ static ImBuf *avi_fetchibuf(struct anim 
   int *tmp;
   int y;
 
-  if (anim == nullptr) {
+  if (anim == nullptr || anim->pFormatCtx == nullptr) {
     return nullptr;
   }
 
