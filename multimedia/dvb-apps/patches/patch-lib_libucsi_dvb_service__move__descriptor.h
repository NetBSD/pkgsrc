$NetBSD: patch-lib_libucsi_dvb_service__move__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/service_move_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/service_move_descriptor.h
@@ -53,9 +53,9 @@ static inline struct dvb_service_move_de
 	if (d->len != (sizeof(struct dvb_service_move_descriptor) - 2))
 		return NULL;
 
-	bswap16((uint8_t*) d + 2);
-	bswap16((uint8_t*) d + 4);
-	bswap16((uint8_t*) d + 6);
+	ubswap16((uint8_t*) d + 2);
+	ubswap16((uint8_t*) d + 4);
+	ubswap16((uint8_t*) d + 6);
 
 	return (struct dvb_service_move_descriptor*) d;
 }
