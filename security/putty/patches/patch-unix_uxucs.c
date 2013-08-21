$NetBSD: patch-unix_uxucs.c,v 1.1.6.1 2013/08/21 19:40:13 tron Exp $

--- unix/uxucs.c.orig	2013-07-22 07:12:05.000000000 +0000
+++ unix/uxucs.c
@@ -72,7 +72,7 @@ int wc_to_mb(int codepage, int flags, co
 	memset(&state, 0, sizeof state);
 
 	while (wclen > 0) {
-	    int i = wcrtomb(output, wcstr[0], &state);
+	    size_t i = wcrtomb(output, wcstr[0], &state);
 	    if (i == (size_t)-1 || i > n - mblen)
 		break;
 	    memcpy(mbstr+n, output, i);
