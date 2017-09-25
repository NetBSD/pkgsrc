$NetBSD: patch-server_util_avidump_avidump.c,v 1.1 2017/09/25 22:30:06 joerg Exp $

--- server/util/avidump/avidump.c.orig	2017-09-25 16:57:46.071322771 +0000
+++ server/util/avidump/avidump.c
@@ -52,7 +52,7 @@ static struct {
   { NULL, 0}, 
 };
 
-static dump_video_sizes (avi_t* aviFile)
+static void dump_video_sizes (avi_t* aviFile)
 {
   long frames = AVI_video_frames(aviFile);
   long ix;
