$NetBSD: patch-lib_libucsi_atsc_dcct__section.c,v 1.1 2011/07/15 22:59:20 jmcneill Exp $

--- lib/libucsi/atsc/dcct_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/atsc/dcct_section.c
@@ -39,10 +39,10 @@ struct atsc_dcct_section *atsc_dcct_sect
 			return NULL;
 		struct atsc_dcct_test *test = (struct atsc_dcct_test *) (buf+pos);
 
-		bswap24(buf+pos);
-		bswap24(buf+pos+3);
-		bswap32(buf+pos+6);
-		bswap32(buf+pos+10);
+		ubswap24(buf+pos);
+		ubswap24(buf+pos+3);
+		ubswap32(buf+pos+6);
+		ubswap32(buf+pos+10);
 
 		pos += sizeof(struct atsc_dcct_test);
 		for(termidx =0; termidx < test->dcc_term_count; termidx++) {
@@ -50,8 +50,8 @@ struct atsc_dcct_section *atsc_dcct_sect
 				return NULL;
 			struct atsc_dcct_term *term = (struct atsc_dcct_term *) (buf+pos);
 
-			bswap64(buf+pos+1);
-			bswap16(buf+pos+9);
+			ubswap64(buf+pos+1);
+			ubswap16(buf+pos+9);
 
 			pos += sizeof(struct atsc_dcct_term);
 			if (len < (pos + term->descriptors_length))
@@ -66,7 +66,7 @@ struct atsc_dcct_section *atsc_dcct_sect
 			return NULL;
 		struct atsc_dcct_test_part2 *part2 = (struct atsc_dcct_test_part2 *) (buf+pos);
 
-		bswap16(buf+pos);
+		ubswap16(buf+pos);
 
 		pos += sizeof(struct atsc_dcct_test_part2);
 		if (len < (pos + part2->descriptors_length))
@@ -80,7 +80,7 @@ struct atsc_dcct_section *atsc_dcct_sect
 		return NULL;
 	struct atsc_dcct_section_part2 *part2 = (struct atsc_dcct_section_part2 *) (buf+pos);
 
-	bswap16(buf+pos);
+	ubswap16(buf+pos);
 
 	pos += sizeof(struct atsc_dcct_section_part2);
 	if (len < (pos + part2->descriptors_length))
