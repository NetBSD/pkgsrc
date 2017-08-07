$NetBSD: patch-util_strfile.h,v 1.1 2017/08/07 11:10:32 jperkin Exp $

Make fortune compatible with BSD strfile datfiles.

--- util/strfile.h.orig	1995-03-23 11:04:08.000000000 +0000
+++ util/strfile.h
@@ -43,14 +43,14 @@
 
 typedef struct {				/* information table */
 #define	VERSION		1
-	unsigned long	str_version;		/* version number */
-	unsigned long	str_numstr;		/* # of strings in the file */
-	unsigned long	str_longlen;		/* length of longest string */
-	unsigned long	str_shortlen;		/* length of shortest string */
+	uint32_t	str_version;		/* version number */
+	uint32_t	str_numstr;		/* # of strings in the file */
+	uint32_t	str_longlen;		/* length of longest string */
+	uint32_t	str_shortlen;		/* length of shortest string */
 #define	STR_RANDOM	0x1			/* randomized pointers */
 #define	STR_ORDERED	0x2			/* ordered pointers */
 #define	STR_ROTATED	0x4			/* rot-13'd text */
-	unsigned long	str_flags;		/* bit field for flags */
+	uint32_t	str_flags;		/* bit field for flags */
 	unsigned char	stuff[4];		/* long aligned space */
 #define	str_delim	stuff[0]		/* delimiting character */
 } STRFILE;
