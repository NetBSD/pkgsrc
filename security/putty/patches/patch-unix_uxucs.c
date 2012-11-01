$NetBSD: patch-unix_uxucs.c,v 1.1 2012/11/01 19:32:44 joerg Exp $

--- unix/uxucs.c.orig	2012-10-30 22:26:02.000000000 +0000
+++ unix/uxucs.c
@@ -76,7 +76,7 @@ int wc_to_mb(int codepage, int flags, wc
 	setlocale(LC_CTYPE, "");
 
 	while (wclen > 0) {
-	    int i = wcrtomb(output, wcstr[0], &state);
+	    size_t i = wcrtomb(output, wcstr[0], &state);
 	    if (i == (size_t)-1 || i > n - mblen)
 		break;
 	    memcpy(mbstr+n, output, i);
