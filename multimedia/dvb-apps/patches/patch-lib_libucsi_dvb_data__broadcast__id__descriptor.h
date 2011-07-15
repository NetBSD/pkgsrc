$NetBSD: patch-lib_libucsi_dvb_data__broadcast__id__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/data_broadcast_id_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/data_broadcast_id_descriptor.h
@@ -89,7 +89,7 @@ static inline struct dvb_data_broadcast_
 	if (d->len < (sizeof(struct dvb_data_broadcast_id_descriptor) - 2))
 		return NULL;
 
-	bswap16((uint8_t*) d + 2);
+	ubswap16((uint8_t*) d + 2);
 
 	return (struct dvb_data_broadcast_id_descriptor*) d;
 }
@@ -190,7 +190,7 @@ static inline struct dvb_ip_mac_notifica
 	if (d->platform_id_data_length == 0)
 		return NULL;
 
-	bswap32((uint8_t *) d + sizeof(struct dvb_id_selector_byte_000b));
+	ubswap32((uint8_t *) d + sizeof(struct dvb_id_selector_byte_000b));
 
 	return (struct dvb_ip_mac_notification_info *) ((uint8_t *) d + sizeof(struct dvb_id_selector_byte_000b));
 }
@@ -207,7 +207,7 @@ static inline struct dvb_ip_mac_notifica
 	if (next >= end)
 		return NULL;
 
-	bswap32(next);
+	ubswap32(next);
 
 	return (struct dvb_ip_mac_notification_info *) next;
 }
