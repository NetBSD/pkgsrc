$NetBSD: patch-lib_libucsi_mpeg_metadata__pointer__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/mpeg/metadata_pointer_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/mpeg/metadata_pointer_descriptor.h
@@ -125,14 +125,14 @@ static inline struct mpeg_metadata_point
 	if (len < sizeof(struct mpeg_metadata_pointer_descriptor))
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
 
@@ -144,7 +144,7 @@ static inline struct mpeg_metadata_point
 	if (id == 0xff) {
 		if (len < (pos+4))
 			return NULL;
-		bswap32(buf+pos);
+		ubswap32(buf+pos);
 		pos += 4;
 	}
 
@@ -164,15 +164,15 @@ static inline struct mpeg_metadata_point
 	if (flags->mpeg_carriage_flags < 3) {
 		if (len < (pos + 2))
 			return NULL;
-		bswap16(buf+pos);
+		ubswap16(buf+pos);
 		pos += 2;
 	}
 
 	if (flags->mpeg_carriage_flags == 1) {
 		if (len < (pos + 4))
 			return NULL;
-		bswap16(buf+pos);
-		bswap16(buf+pos+2);
+		ubswap16(buf+pos);
+		ubswap16(buf+pos+2);
 		pos += 4;
 	}
 
