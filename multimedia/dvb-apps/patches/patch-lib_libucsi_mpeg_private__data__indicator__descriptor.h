$NetBSD: patch-lib_libucsi_mpeg_private__data__indicator__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/mpeg/private_data_indicator_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/mpeg/private_data_indicator_descriptor.h
@@ -51,7 +51,7 @@ static inline struct mpeg_private_data_i
 	if (d->len != (sizeof(struct mpeg_private_data_indicator_descriptor) - 2))
 		return NULL;
 
-	bswap32((uint8_t*) d + 2);
+	ubswap32((uint8_t*) d + 2);
 
 	return (struct mpeg_private_data_indicator_descriptor*) d;
 }
