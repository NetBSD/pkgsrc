$NetBSD: patch-lib_libucsi_dvb_pdc__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/pdc_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/pdc_descriptor.h
@@ -52,7 +52,7 @@ static inline struct dvb_pdc_descriptor*
 	if (d->len != (sizeof(struct dvb_pdc_descriptor) - 2))
 		return NULL;
 
-	bswap24((uint8_t*) d + 2);
+	ubswap24((uint8_t*) d + 2);
 
 	return (struct dvb_pdc_descriptor*) d;
 }
