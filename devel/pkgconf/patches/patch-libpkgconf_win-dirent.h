$NetBSD: patch-libpkgconf_win-dirent.h,v 1.1 2023/03/17 20:20:45 riastradh Exp $

Fix ctype(3) misuse.
https://github.com/pkgconf/pkgconf/issues/291
https://github.com/pkgconf/pkgconf/pull/292

--- libpkgconf/win-dirent.h.orig	2022-06-26 03:11:36.000000000 +0000
+++ libpkgconf/win-dirent.h
@@ -912,7 +912,7 @@ static int strverscmp(const char *a, con
 
 	/* Count backwards and find the leftmost digit */
 	j = i;
-	while (j > 0 && isdigit(a[j-1])) {
+	while (j > 0 && isdigit((unsigned char)a[j-1])) {
 		--j;
 	}
 
@@ -924,23 +924,24 @@ static int strverscmp(const char *a, con
 		}
 
 		/* String with more digits is smaller, e.g 002 < 01 */
-		if (isdigit(a[j])) {
-			if (!isdigit(b[j])) {
+		if (isdigit((unsigned char)a[j])) {
+			if (!isdigit((unsigned char)b[j])) {
 				return -1;
 			}
-		} else if (isdigit(b[j])) {
+		} else if ((unsigned char)isdigit(b[j])) {
 			return 1;
 		}
-	} else if (isdigit(a[j]) && isdigit(b[j])) {
+	} else if ((unsigned char)isdigit(a[j]) &&
+	    isdigit((unsigned char)b[j])) {
 		/* Numeric comparison */
 		size_t k1 = j;
 		size_t k2 = j;
 
 		/* Compute number of digits in each string */
-		while (isdigit(a[k1])) {
+		while (isdigit((unsigned char)a[k1])) {
 			k1++;
 		}
-		while (isdigit(b[k2])) {
+		while (isdigit((unsigned char)b[k2])) {
 			k2++;
 		}
 
