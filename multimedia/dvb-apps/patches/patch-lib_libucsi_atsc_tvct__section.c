$NetBSD: patch-lib_libucsi_atsc_tvct__section.c,v 1.1 2011/07/15 22:59:20 jmcneill Exp $

--- lib/libucsi/atsc/tvct_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/atsc/tvct_section.c
@@ -42,13 +42,13 @@ struct atsc_tvct_section *atsc_tvct_sect
 
 		pos += 7*2;
 
-		bswap32(buf+pos);
-		bswap32(buf+pos+4);
-		bswap16(buf+pos+8);
-		bswap16(buf+pos+10);
-		bswap16(buf+pos+12);
-		bswap16(buf+pos+14);
-		bswap16(buf+pos+16);
+		ubswap32(buf+pos);
+		ubswap32(buf+pos+4);
+		ubswap16(buf+pos+8);
+		ubswap16(buf+pos+10);
+		ubswap16(buf+pos+12);
+		ubswap16(buf+pos+14);
+		ubswap16(buf+pos+16);
 		pos+=18;
 
 		if ((pos + channel->descriptors_length) > len)
@@ -63,7 +63,7 @@ struct atsc_tvct_section *atsc_tvct_sect
 		return NULL;
 	struct atsc_tvct_section_part2 *part2 = (struct atsc_tvct_section_part2 *) (buf+pos);
 
-	bswap16(buf+pos);
+	ubswap16(buf+pos);
 	pos+=2;
 
 	if ((pos + part2->descriptors_length) > len)
