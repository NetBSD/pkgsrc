$NetBSD: patch-lib_libucsi_mpeg_ibp__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/mpeg/ibp_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/mpeg/ibp_descriptor.h
@@ -53,7 +53,7 @@ static inline struct mpeg_ibp_descriptor
 	if (d->len != (sizeof(struct mpeg_ibp_descriptor) - 2))
 		return NULL;
 
-	bswap16((uint8_t*) d + 2);
+	ubswap16((uint8_t*) d + 2);
 
 	return (struct mpeg_ibp_descriptor*) d;
 }
