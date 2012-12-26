$NetBSD: patch-codetozen.c,v 1.1 2012/12/26 21:21:38 dholland Exp $

- declare own functions
- avoid implicit int
- silence warnings about assignments in conditionals

--- codetozen.c~	1994-03-23 21:57:34.000000000 +0000
+++ codetozen.c
@@ -3,6 +3,8 @@
 /* v1.00  1993 10/10	Ogasawara Hiroyuki		*/
 /*			oga@dgw.yz.yamagata-u.ac.jp	*/
 
+#include "misc.h"
+
 #define	HIRAGANA	0
 #define	ZENMAP		0
 
@@ -87,6 +89,7 @@ static unsigned short	zenmap1[]= {
 };
 #endif	/* ZENMAP */
 
+unsigned int
 CodeToZen( code )
 unsigned int	code;
 {
@@ -94,10 +97,10 @@ unsigned int	code;
 	if( code < 0x100 && (zen= zenmap0[code]) != 0xff ){
 		unsigned int	next= getcode();
 		if( next == 0xde ){
-			if( zen2= zenmap1[zen+0x40] )
+			if( (zen2= zenmap1[zen+0x40]) != 0 )
 				return	zen2;
 		}else if( next == 0xdf ){
-			if( zen2= zenmap1[zen+0x80] )
+			if( (zen2= zenmap1[zen+0x80]) != 0 )
 				return	zen2;
 		}
 		ungetcode( next );
