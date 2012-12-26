$NetBSD: patch-euctocode.c,v 1.1 2012/12/26 21:21:38 dholland Exp $

- declare own functions
- avoid implicit int
- silence warnings about assignments in conditionals

--- euctocode.c~	1994-03-23 21:57:34.000000000 +0000
+++ euctocode.c
@@ -4,6 +4,7 @@
 /*			oga@dgw.yz.yamagata-u.ac.jp	*/
 
 #include	"kanjicode.h"
+#include	"misc.h"
 
 static unsigned char	eucmap_h[]= {
 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
@@ -44,6 +45,7 @@ static unsigned char	eucmap_l[]= {
 };
 
 
+unsigned int
 EucToCode( code )
 unsigned int	code;
 {
@@ -52,7 +54,7 @@ unsigned int	code;
 
 	if( (code= eucmap_h[hi]) != 0xff ){
 		if( code ){
-			if( low= eucmap_h[low] )
+			if( (low= eucmap_h[low]) != 0 )
 				return	PACKWORD( code, low );
 		}else if( eucmap_l[low] ){
 			return	low;
