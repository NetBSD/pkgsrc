$NetBSD: patch-lib_libucsi_mpeg_multiplex__buffer__utilization__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/mpeg/multiplex_buffer_utilization_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/mpeg/multiplex_buffer_utilization_descriptor.h
@@ -54,8 +54,8 @@ static inline struct mpeg_multiplex_buff
 	if (d->len != (sizeof(struct mpeg_multiplex_buffer_utilization_descriptor) - 2))
 		return NULL;
 
-	bswap16((uint8_t*) d + 2);
-	bswap16((uint8_t*) d + 4);
+	ubswap16((uint8_t*) d + 2);
+	ubswap16((uint8_t*) d + 4);
 
 	return (struct mpeg_multiplex_buffer_utilization_descriptor*) d;
 }
