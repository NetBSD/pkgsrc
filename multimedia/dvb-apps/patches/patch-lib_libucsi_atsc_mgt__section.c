$NetBSD: patch-lib_libucsi_atsc_mgt__section.c,v 1.1 2011/07/15 22:59:20 jmcneill Exp $

--- lib/libucsi/atsc/mgt_section.c.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/atsc/mgt_section.c
@@ -32,7 +32,7 @@ struct atsc_mgt_section *atsc_mgt_sectio
 	if (len < sizeof(struct atsc_mgt_section))
 		return NULL;
 
-	bswap16(buf + pos);
+	ubswap16(buf + pos);
 	pos += 2;
 
 	// we cannot use the tables_defined value here because of the braindead ATSC spec!
@@ -42,10 +42,10 @@ struct atsc_mgt_section *atsc_mgt_sectio
 			return NULL;
 		struct atsc_mgt_table *table = (struct atsc_mgt_table *) (buf+pos);
 
-		bswap16(buf+pos);
-		bswap16(buf+pos+2);
-		bswap32(buf+pos+5);
-		bswap16(buf+pos+9);
+		ubswap16(buf+pos);
+		ubswap16(buf+pos+2);
+		ubswap32(buf+pos+5);
+		ubswap16(buf+pos+9);
 
 		pos += sizeof(struct atsc_mgt_table);
 		if ((pos + table->table_type_descriptors_length) > len)
@@ -60,7 +60,7 @@ struct atsc_mgt_section *atsc_mgt_sectio
 		return NULL;
 	struct atsc_mgt_section_part2 *part2 = (struct atsc_mgt_section_part2 *) (buf+pos);
 
-	bswap16(buf+pos);
+	ubswap16(buf+pos);
 
 	pos += sizeof(struct atsc_mgt_section_part2);
 	if ((pos + part2->descriptors_length) > len)
