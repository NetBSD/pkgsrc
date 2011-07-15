$NetBSD: patch-lib_libucsi_mpeg_metadata__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/mpeg/metadata_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/mpeg/metadata_descriptor.h
@@ -144,14 +144,14 @@ static inline struct mpeg_metadata_descr
 	if (len < sizeof(struct mpeg_metadata_descriptor))
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
 
@@ -163,7 +163,7 @@ static inline struct mpeg_metadata_descr
 	if (id == 0xff) {
 		if (len < (pos+4))
 			return NULL;
-		bswap32(buf+pos);
+		ubswap32(buf+pos);
 		pos += 4;
 	}
 
