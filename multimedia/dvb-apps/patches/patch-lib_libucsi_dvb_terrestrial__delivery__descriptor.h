$NetBSD: patch-lib_libucsi_dvb_terrestrial__delivery__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/terrestrial_delivery_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/terrestrial_delivery_descriptor.h
@@ -64,8 +64,8 @@ static inline struct dvb_terrestrial_del
 	if (d->len != (sizeof(struct dvb_terrestrial_delivery_descriptor) - 2))
 		return NULL;
 
-	bswap32((uint8_t*) d + 2);
-	bswap32((uint8_t*) d + 9);
+	ubswap32((uint8_t*) d + 2);
+	ubswap32((uint8_t*) d + 9);
 
 	return (struct dvb_terrestrial_delivery_descriptor*) d;
 }
