$NetBSD: patch-lib_libucsi_atsc_caption__service__descriptor.h,v 1.1 2011/07/15 22:59:20 jmcneill Exp $

--- lib/libucsi/atsc/caption_service_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/atsc/caption_service_descriptor.h
@@ -78,7 +78,7 @@ static inline struct atsc_caption_servic
 		if (d->len < (pos + sizeof(struct atsc_caption_service_entry)))
 			return NULL;
 
-		bswap16(buf+pos+4);
+		ubswap16(buf+pos+4);
 
 		pos += sizeof(struct atsc_caption_service_entry);
 	}
