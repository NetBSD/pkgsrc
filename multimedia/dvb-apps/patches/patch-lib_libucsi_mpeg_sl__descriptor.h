$NetBSD: patch-lib_libucsi_mpeg_sl__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/mpeg/sl_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/mpeg/sl_descriptor.h
@@ -51,7 +51,7 @@ static inline struct mpeg_sl_descriptor*
 	if (d->len != (sizeof(struct mpeg_sl_descriptor) - 2))
 		return NULL;
 
-	bswap16((uint8_t*) d + 2);
+	ubswap16((uint8_t*) d + 2);
 
 	return (struct mpeg_sl_descriptor*) d;
 }
