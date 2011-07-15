$NetBSD: patch-lib_libucsi_dvb_private__data__specifier__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/private_data_specifier_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/private_data_specifier_descriptor.h
@@ -51,7 +51,7 @@ static inline struct dvb_private_data_sp
 	if (d->len != (sizeof(struct dvb_private_data_specifier_descriptor) - 2))
 		return NULL;
 
-	bswap32((uint8_t*) d + 2);
+	ubswap32((uint8_t*) d + 2);
 
 	return (struct dvb_private_data_specifier_descriptor*) d;
 }
