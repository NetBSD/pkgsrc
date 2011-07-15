$NetBSD: patch-lib_libucsi_mpeg_video__window__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/mpeg/video_window_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/mpeg/video_window_descriptor.h
@@ -52,7 +52,7 @@ static inline struct mpeg_video_window_d
 	if (d->len != (sizeof(struct mpeg_video_window_descriptor) - 2))
 		return NULL;
 
-	bswap32((uint8_t*) d + 2);
+	ubswap32((uint8_t*) d + 2);
 
 	return (struct mpeg_video_window_descriptor*) d;
 }
