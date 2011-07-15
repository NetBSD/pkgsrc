$NetBSD: patch-lib_libucsi_dvb_ip__mac__stream__location__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/ip_mac_stream_location_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/ip_mac_stream_location_descriptor.h
@@ -58,10 +58,10 @@ static inline struct dvb_ip_mac_stream_l
 	if (d->len != (sizeof(struct dvb_ip_mac_stream_location_descriptor) - 2))
 		return NULL;
 
-	bswap16(buf);
-	bswap16(buf+2);
-	bswap16(buf+4);
-	bswap16(buf+6);
+	ubswap16(buf);
+	ubswap16(buf+2);
+	ubswap16(buf+4);
+	ubswap16(buf+6);
 
 	return (struct dvb_ip_mac_stream_location_descriptor*) d;
 }
