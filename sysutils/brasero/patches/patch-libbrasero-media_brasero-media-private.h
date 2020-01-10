$NetBSD: patch-libbrasero-media_brasero-media-private.h,v 1.1 2020/01/10 21:18:21 joerg Exp $

--- libbrasero-media/brasero-media-private.h.orig	2020-01-08 23:19:51.813099961 +0000
+++ libbrasero-media/brasero-media-private.h
@@ -64,7 +64,7 @@ brasero_media_to_string (BraseroMedia me
 void
 brasero_media_message (const gchar *location,
 		       const gchar *format,
-		       ...);
+		       ...) G_GNUC_PRINTF(2,3);
 
 G_END_DECLS
 
