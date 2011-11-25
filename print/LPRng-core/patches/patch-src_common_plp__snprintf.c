$NetBSD: patch-src_common_plp__snprintf.c,v 1.1 2011/11/25 22:15:18 joerg Exp $

--- src/common/plp_snprintf.c.orig	2004-09-24 20:19:58.000000000 +0000
+++ src/common/plp_snprintf.c
@@ -933,7 +933,7 @@
 	}
 	convert[2*i] = 0;
 
-	place = safestrlen(convert);
+	place = strlen(convert);
 	padlen = len - place;
 	if( padlen < 0 ) padlen = 0;
 	if( ljust ) padlen = -padlen;
@@ -991,13 +991,13 @@
 	if( ljust ) mystrcat(formatstr, "-" ); /* 1 */
 	if( zpad ) mystrcat(formatstr, "0" );	/* 1 */
 	if( len >= 0 ){
-		sprintf( formatstr+safestrlen(formatstr), "%d", len ); /* 3 */
+		sprintf( formatstr+strlen(formatstr), "%d", len ); /* 3 */
 	}
 	if( precision >= 0 ){
-		sprintf( formatstr+safestrlen(formatstr), ".%d", precision ); /* 3 */
+		sprintf( formatstr+strlen(formatstr), ".%d", precision ); /* 3 */
 	}
 	/* format string will be at most 10 chars long ... */
-	sprintf( formatstr+safestrlen(formatstr), "%c", fmt );
+	sprintf( formatstr+strlen(formatstr), "%c", fmt );
 	/* this is easier than trying to do the portable dtostr */
 	/* fprintf(stderr,"format string '%s'\n", formatstr); */
 	sprintf( convert, formatstr, value );
