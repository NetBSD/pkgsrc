$NetBSD: patch-lib_libucsi_section.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/section.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/section.h
@@ -112,7 +112,7 @@ static inline struct section * section_c
 	if (len < 3)
 		return NULL;
 
-	bswap16(buf+1);
+	ubswap16(buf+1);
 
 	if (len != ret->length + 3U)
 		return NULL;
@@ -134,9 +134,9 @@ static inline int section_check_crc(stru
 	uint32_t crc;
 
 	/* the crc check has to be performed on the unswapped data */
-	bswap16(buf+1);
+	ubswap16(buf+1);
 	crc = crc32(CRC32_INIT, buf, len);
-	bswap16(buf+1);
+	ubswap16(buf+1);
 
 	/* the crc check includes the crc value,
 	 * the result should therefore be zero.
@@ -165,7 +165,7 @@ static inline struct section_ext * secti
 			return NULL;
 	}
 
-	bswap16((uint8_t *)section + sizeof(struct section));
+	ubswap16((uint8_t *)section + sizeof(struct section));
 
 	return (struct section_ext *)section;
 }
@@ -183,7 +183,7 @@ static inline struct section_ext * secti
 	if (section->syntax_indicator == 0)
 		return NULL;
 
-	bswap16((uint8_t *)section + sizeof(struct section));
+	ubswap16((uint8_t *)section + sizeof(struct section));
 
 	if (update_crc) {
 		uint8_t * buf = (uint8_t *) section;
@@ -191,13 +191,13 @@ static inline struct section_ext * secti
 		uint32_t crc;
 
 		/* the crc has to be performed on the swapped data */
-		bswap16(buf+1);
+		ubswap16(buf+1);
 		crc = crc32(CRC32_INIT, buf, len-4);
-		bswap16(buf+1);
+		ubswap16(buf+1);
 
 		/* update the CRC */
 		*((uint32_t*) (buf+len-4)) = crc;
-		bswap32(buf+len-4);
+		ubswap32(buf+len-4);
 	}
 
 	return (struct section_ext *)section;
