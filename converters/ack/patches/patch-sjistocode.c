$NetBSD: patch-sjistocode.c,v 1.1 2012/12/26 21:21:38 dholland Exp $

- declare own functions
- avoid implicit int
- silence warnings about assignments in conditionals

--- sjistocode.c~	1994-03-23 21:57:36.000000000 +0000
+++ sjistocode.c
@@ -4,6 +4,7 @@
 /*				 oga@dgw.yz.yamagata-u.ac.jp	*/
 
 #include	"kanjicode.h"
+#include	"misc.h"
 
 static unsigned char	sjismap1_h[]={
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
@@ -42,14 +43,15 @@ static unsigned char	sjismap1_l[]={
 0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf8,0xf9,0xfa,0xfb,0xfc,0xfd,0xfe,0x00,0x00,0x00,
 };
 
+unsigned int
 SjisToCode( code )
 unsigned int	code;
 {
 	unsigned int	hi, low;
 
-	if( hi= code>>8 ){
-		if( hi= sjismap1_h[hi] ){
-			if( low= sjismap1_l[code&0xff] ){
+	if( (hi= code>>8) != 0 ){
+		if( (hi= sjismap1_h[hi]) != 0 ){
+			if( (low= sjismap1_l[code&0xff]) != 0 ){
 				if( low & 0x80 )
 					hi++;
 				return	PACKWORD( hi, low&0x7f );
