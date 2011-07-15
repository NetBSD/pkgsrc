$NetBSD: patch-lib_libucsi_dvb_satellite__delivery__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/satellite_delivery_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/satellite_delivery_descriptor.h
@@ -59,9 +59,9 @@ static inline struct dvb_satellite_deliv
 	if (d->len < (sizeof(struct dvb_satellite_delivery_descriptor) - 2))
 		return NULL;
 
-	bswap32((uint8_t*) d + 2);
-	bswap16((uint8_t*) d + 6);
-	bswap32((uint8_t*) d + 9);
+	ubswap32((uint8_t*) d + 2);
+	ubswap16((uint8_t*) d + 6);
+	ubswap32((uint8_t*) d + 9);
 
 	return (struct dvb_satellite_delivery_descriptor*) d;
 }
