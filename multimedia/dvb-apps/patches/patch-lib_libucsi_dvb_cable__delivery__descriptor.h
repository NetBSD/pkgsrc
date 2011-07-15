$NetBSD: patch-lib_libucsi_dvb_cable__delivery__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/cable_delivery_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/cable_delivery_descriptor.h
@@ -56,9 +56,9 @@ static inline struct dvb_cable_delivery_
 	if (d->len != (sizeof(struct dvb_cable_delivery_descriptor) - 2))
 		return NULL;
 
-	bswap32((uint8_t*) d + 2);
-	bswap16((uint8_t*) d + 6);
-	bswap32((uint8_t*) d + 9);
+	ubswap32((uint8_t*) d + 2);
+	ubswap16((uint8_t*) d + 6);
+	ubswap32((uint8_t*) d + 9);
 
 	return (struct dvb_cable_delivery_descriptor*) d;
 }
