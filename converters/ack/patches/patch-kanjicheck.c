$NetBSD: patch-kanjicheck.c,v 1.1 2012/12/26 21:21:38 dholland Exp $

- declare own functions
- declare void functions void
- silence gcc45 warnings about braces

--- kanjicheck.c.orig	1994-07-26 09:03:39.000000000 +0000
+++ kanjicheck.c
@@ -7,6 +7,7 @@
 #include	<stdio.h>
 #include	"kanjicode.h"
 #include	"ackstring.h"
+#include	"misc.h"
 
 #if KCCHECK
 # define	putcode(cmd)
@@ -68,6 +69,7 @@ unsigned char	euccheck_h[]={
 };
 #endif
 
+void
 #if KCCHECK
 CodeCheckAll( cp )
 #else
@@ -104,8 +106,9 @@ T_KANJI	*cp;
 #endif
 		case 8:
 			CTRLINC;
-			if( !(cp->flag & fUNIX) )
+			if( !(cp->flag & fUNIX) ) {
 				putcode( code );
+			}
 			break;
 		case 5:	/* SI locking shift G0 -> GL */
 			CTRLINC;
@@ -172,8 +175,9 @@ T_KANJI	*cp;
 			}
 			ASCIIINC;
 		case 0: /* through */
-			if( cp->outcode == JIS )
+			if( cp->outcode == JIS ) {
 				setjismode();
+			}
 #if KCCHECK
 			if( code == ' ' )
 				ASCIIINC;
