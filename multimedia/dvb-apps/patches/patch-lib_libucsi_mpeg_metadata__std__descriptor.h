$NetBSD: patch-lib_libucsi_mpeg_metadata__std__descriptor.h,v 1.1 2011/07/15 22:59:21 jmcneill Exp $

--- lib/libucsi/mpeg/metadata_std_descriptor.h.orig	2011-06-28 05:50:24.000000000 +0000
+++ lib/libucsi/mpeg/metadata_std_descriptor.h
@@ -58,9 +58,9 @@ static inline struct mpeg_metadata_std_d
 	if (d->len != (sizeof(struct mpeg_metadata_std_descriptor) - 2))
 		return NULL;
 
-	bswap24(buf + 2);
-	bswap24(buf + 5);
-	bswap24(buf + 8);
+	ubswap24(buf + 2);
+	ubswap24(buf + 5);
+	ubswap24(buf + 8);
 
 	return (struct mpeg_metadata_std_descriptor*) d;
 }
