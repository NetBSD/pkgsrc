$NetBSD: patch-codetosjis.c,v 1.1 2012/12/26 21:21:38 dholland Exp $

- declare own functions
- avoid implicit int
- silence warnings about assignments in conditionals

--- codetosjis.c~	1994-03-23 21:57:34.000000000 +0000
+++ codetosjis.c
@@ -4,6 +4,7 @@
 /*			oga@dgw.yz.yamagata-u.ac.jp	*/
 
 #include	"kanjicode.h"
+#include	"misc.h"
 
 static unsigned char	sjismap2_h[]={
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
@@ -42,6 +43,7 @@ static unsigned char	sjismap2_l[]={
 0xee,0xef,0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0x00,
 };
 
+unsigned int
 CodeToSjis( code )
 unsigned int	code;
 {
@@ -49,10 +51,10 @@ unsigned int	code;
 			low= code&0x7f;
 
 	if( hi ){
-		if( code= sjismap2_h[hi] ){
+		if( (code= sjismap2_h[hi]) != 0 ){
 			if( !(hi & 1) )
 				low+= 0x80;
-			if( low= sjismap2_l[low] )
+			if( (low= sjismap2_l[low]) != 0 )
 				return	PACKWORD( code, low );
 		}
 		return	ERRCODE;
