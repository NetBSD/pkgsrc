$NetBSD: patch-lib_libucsi_atsc_dccsct__section.c,v 1.1 2011/07/15 22:59:20 jmcneill Exp $

--- lib/libucsi/atsc/dccsct_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/atsc/dccsct_section.c
@@ -65,7 +65,7 @@ struct atsc_dccsct_section *atsc_dccsct_
 			int sublen = sizeof(struct atsc_dccsct_update_new_county);
 			if (update->update_data_length < sublen)
 				return NULL;
-			bswap16(buf+pos+1);
+			ubswap16(buf+pos+1);
 
 			if (atsc_text_validate(buf+pos+sublen, update->update_data_length - sublen))
 				return NULL;
@@ -78,7 +78,7 @@ struct atsc_dccsct_section *atsc_dccsct_
 			return NULL;
 		struct atsc_dccsct_update_part2 *part2 = (struct atsc_dccsct_update_part2 *) buf + pos;
 
-		bswap16(buf+pos);
+		ubswap16(buf+pos);
 
 		pos += sizeof(struct atsc_dccsct_update_part2);
 		if (len < (pos + part2->descriptors_length))
@@ -93,7 +93,7 @@ struct atsc_dccsct_section *atsc_dccsct_
 		return NULL;
 	struct atsc_dccsct_section_part2 *part2 = (struct atsc_dccsct_section_part2 *) (buf+pos);
 
-	bswap16(buf+pos);
+	ubswap16(buf+pos);
 
 	pos += sizeof(struct atsc_dccsct_section_part2);
 	if (len < (pos + part2->descriptors_length))
