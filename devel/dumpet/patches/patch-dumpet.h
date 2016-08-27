$NetBSD: patch-dumpet.h,v 1.1 2016/08/27 11:53:39 nonaka Exp $

--- dumpet.h.orig	2010-08-25 16:54:11.000000000 +0000
+++ dumpet.h	2016-08-26 00:18:41.000000000 +0000
@@ -39,7 +39,8 @@ static inline int read_sector(FILE *iso,
 
 	if (n != 1) {
 		int errnum = errno;
-		fprintf(stderr, "dumpet: Error reading image: %m\n");
+		fprintf(stderr, "dumpet: Error reading image: %s\n",
+		    strerror(errno));
 		errno = errnum;
 		return -errno;
 	}
@@ -54,7 +55,8 @@ static inline int write_sector(FILE *iso
 
 	if (n != 1) {
 		int errnum = errno;
-		fprintf(stderr, "dumpet: Error writing image: %m\n");
+		fprintf(stderr, "dumpet: Error writing image: %s\n",
+		    strerror(errno));
 		errno = errnum;
 		return -errno;
 	}
