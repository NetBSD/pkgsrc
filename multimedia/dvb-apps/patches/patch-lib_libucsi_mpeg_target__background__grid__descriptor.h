$NetBSD: patch-lib_libucsi_mpeg_target__background__grid__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/mpeg/target_background_grid_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/mpeg/target_background_grid_descriptor.h
@@ -54,7 +54,7 @@ static inline struct mpeg_target_backgro
 	if (d->len != (sizeof(struct mpeg_target_background_grid_descriptor) - 2))
 		return NULL;
 
-	bswap32((uint8_t*) d + 2);
+	ubswap32((uint8_t*) d + 2);
 
 	return (struct mpeg_target_background_grid_descriptor*) d;
 }
