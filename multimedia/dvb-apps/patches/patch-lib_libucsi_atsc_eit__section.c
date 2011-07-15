$NetBSD: patch-lib_libucsi_atsc_eit__section.c,v 1.1 2011/07/15 22:59:20 jmcneill Exp $

--- lib/libucsi/atsc/eit_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/atsc/eit_section.c
@@ -38,9 +38,9 @@ struct atsc_eit_section *atsc_eit_sectio
 			return NULL;
 		struct atsc_eit_event *event = (struct atsc_eit_event *) (buf+pos);
 
-		bswap16(buf+pos);
-		bswap32(buf+pos+2);
-		bswap32(buf+pos+6);
+		ubswap16(buf+pos);
+		ubswap32(buf+pos+2);
+		ubswap32(buf+pos+6);
 
 		pos += sizeof(struct atsc_eit_event);
 		if (len < (pos + event->title_length))
@@ -53,7 +53,7 @@ struct atsc_eit_section *atsc_eit_sectio
 			return NULL;
 		struct atsc_eit_event_part2 *part2 = (struct atsc_eit_event_part2 *) (buf+pos);
 
-		bswap16(buf+pos);
+		ubswap16(buf+pos);
 
 		pos += sizeof(struct atsc_eit_event_part2);
 		if (len < (pos + part2->descriptors_length))
