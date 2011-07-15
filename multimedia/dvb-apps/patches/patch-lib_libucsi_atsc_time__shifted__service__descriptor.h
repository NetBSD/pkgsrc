$NetBSD: patch-lib_libucsi_atsc_time__shifted__service__descriptor.h,v 1.1 2011/07/15 22:59:20 jmcneill Exp $

--- lib/libucsi/atsc/time_shifted_service_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/atsc/time_shifted_service_descriptor.h
@@ -76,8 +76,8 @@ static inline struct atsc_time_shifted_s
 		if (d->len < (pos + sizeof(struct atsc_time_shifted_service)))
 			return NULL;
 
-		bswap16(buf+pos);
-		bswap24(buf+pos+2);
+		ubswap16(buf+pos);
+		ubswap24(buf+pos+2);
 
 		pos += sizeof(struct atsc_time_shifted_service);
 	}
