$NetBSD: patch-src_profiles.c,v 1.1 2020/04/23 15:24:00 nia Exp $

Fix build with newer ffmpeg.

--- src/profiles.c.orig	2012-02-26 19:34:00.000000000 +0000
+++ src/profiles.c
@@ -287,7 +287,7 @@ dlna_guess_media_profile (dlna_t *dlna, 
     return NULL;
   }
 
-  if (av_find_stream_info (ctx) < 0)
+  if (avformat_find_stream_info (ctx, NULL) < 0)
   {
     if (dlna->verbosity)
       fprintf (stderr, "can't find stream info\n");
@@ -334,7 +334,7 @@ dlna_guess_media_profile (dlna_t *dlna, 
     p = p->next;
   }
 
-  av_close_input_file (ctx);
+  avformat_close_input (&ctx);
   free (codecs);
   return profile;
 }
