$NetBSD: patch-src_plugins_metadata__libavformat.c,v 1.1 2012/09/24 10:29:36 ryoon Exp $

--- src/plugins/metadata_libavformat.c.orig	2010-01-11 19:12:58.000000000 +0000
+++ src/plugins/metadata_libavformat.c
@@ -149,21 +149,21 @@ int fuppes_metadata_read(plugin_info* pl
 		} */
 
 		switch(pStream->codec->codec_type) {
-			case CODEC_TYPE_VIDEO:
+			case AVMEDIA_TYPE_VIDEO:
 				metadata->type		= MD_VIDEO;
 				metadata->width 	= pStream->codec->width;
 				metadata->height	= pStream->codec->height;
 				set_value(&metadata->video_codec, codec_name);
 				break;
-			case CODEC_TYPE_AUDIO:
+			case AVMEDIA_TYPE_AUDIO:
 				set_value(&metadata->audio_codec, codec_name);
 				if(metadata->type == MD_NONE) {
 					metadata->type = MD_AUDIO;
 				}
 				break;
-			case CODEC_TYPE_DATA:
+			case AVMEDIA_TYPE_DATA:
 				break;
-			case CODEC_TYPE_SUBTITLE:
+			case AVMEDIA_TYPE_SUBTITLE:
 				break;
 			default:
 				break;
