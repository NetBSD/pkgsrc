$NetBSD: patch-lib_libucsi_mpeg_content__labelling__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/mpeg/content_labelling_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/mpeg/content_labelling_descriptor.h
@@ -124,14 +124,14 @@ static inline struct mpeg_content_labell
 	if (len < sizeof(struct mpeg_content_labelling_descriptor))
 		return NULL;
 
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 	id = *((uint16_t*) (buf+pos));
 	pos += 2;
 
 	if (id == 0xffff) {
 		if (len < (pos+4))
 			return NULL;
-		bswap32(buf+pos);
+		ubswap32(buf+pos);
 		pos += 4;
 	}
 
@@ -152,8 +152,8 @@ static inline struct mpeg_content_labell
 	    (flags->content_time_base_indicator == 2)) {
 		if (len < (pos + sizeof(struct mpeg_content_labelling_descriptor_time_base)))
 			return NULL;
-		bswap40(buf+pos);
-		bswap40(buf+pos+5);
+		ubswap40(buf+pos);
+		ubswap40(buf+pos+5);
 		pos += sizeof(struct mpeg_content_labelling_descriptor_time_base);
 	}
 
