$NetBSD: patch-lib_libucsi_mpeg_multiplex__buffer__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/mpeg/multiplex_buffer_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/mpeg/multiplex_buffer_descriptor.h
@@ -53,7 +53,7 @@ static inline struct mpeg_multiplex_buff
 	if (d->len != (sizeof(struct mpeg_multiplex_buffer_descriptor) - 2))
 		return NULL;
 
-	bswap48((uint8_t*) d + 2);
+	ubswap48((uint8_t*) d + 2);
 
 	return (struct mpeg_multiplex_buffer_descriptor*) d;
 }
