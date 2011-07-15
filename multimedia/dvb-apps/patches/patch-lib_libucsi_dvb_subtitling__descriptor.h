$NetBSD: patch-lib_libucsi_dvb_subtitling__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/subtitling_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/subtitling_descriptor.h
@@ -67,8 +67,8 @@ static inline struct dvb_subtitling_desc
 		return NULL;
 
 	while(pos < len) {
-		bswap16(ptr+pos+4);
-		bswap16(ptr+pos+6);
+		ubswap16(ptr+pos+4);
+		ubswap16(ptr+pos+6);
 		pos += sizeof(struct dvb_subtitling_entry);
 	}
 
