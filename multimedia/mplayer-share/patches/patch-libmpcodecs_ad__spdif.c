$NetBSD: patch-libmpcodecs_ad__spdif.c,v 1.1 2021/04/10 13:06:50 ryoon Exp $

* Fix build with ffmpeg4-4.4.
  From upstream revision 38198.

--- libmpcodecs/ad_spdif.c.orig	2016-03-06 13:00:49.000000000 +0000
+++ libmpcodecs/ad_spdif.c
@@ -298,14 +298,8 @@ static void uninit(sh_audio_t *sh)
         if (spdif_ctx->header_written)
             av_write_trailer(lavf_ctx);
         av_freep(&lavf_ctx->pb);
-        if (lavf_ctx->streams) {
-            av_freep(&lavf_ctx->streams[0]->codec);
-            av_freep(&lavf_ctx->streams[0]->info);
-            av_freep(&lavf_ctx->streams[0]);
-        }
-        av_freep(&lavf_ctx->streams);
-        av_freep(&lavf_ctx->priv_data);
+        avformat_free_context(lavf_ctx);
+        lavf_ctx = NULL;
     }
-    av_freep(&lavf_ctx);
     av_freep(&spdif_ctx);
 }
