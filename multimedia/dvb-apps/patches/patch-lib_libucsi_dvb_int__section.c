$NetBSD: patch-lib_libucsi_dvb_int__section.c,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/dvb/int_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/dvb/int_section.c
@@ -32,8 +32,8 @@ struct dvb_int_section * dvb_int_section
 	if (len < sizeof(struct dvb_int_section))
 		return NULL;
 
-	bswap32(buf+8);
-	bswap16(buf+12);
+	ubswap32(buf+8);
+	ubswap16(buf+12);
 	pos += 6;
 
 	if (len - pos < in->platform_descriptors_length)
@@ -48,7 +48,7 @@ struct dvb_int_section * dvb_int_section
 		struct dvb_int_target *s2 = (struct dvb_int_target *) (buf + pos);
 		struct dvb_int_operational_loop *s3;
 
-		bswap16(buf + pos); /* target_descriptor_loop_length swap */
+		ubswap16(buf + pos); /* target_descriptor_loop_length swap */
 
 		if (len - pos < s2->target_descriptors_length)
 			return NULL;
@@ -62,7 +62,7 @@ struct dvb_int_section * dvb_int_section
 
 		s3 = (struct dvb_int_operational_loop *) (buf + pos);
 
-		bswap16(buf + pos); /* operational_descriptor_loop_length swap */
+		ubswap16(buf + pos); /* operational_descriptor_loop_length swap */
 
 		if (len - pos < s3->operational_descriptors_length)
 			return NULL;
