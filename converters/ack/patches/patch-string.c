$NetBSD: patch-string.c,v 1.1 2012/12/26 21:21:38 dholland Exp $

- use standard headers
- declare own functions
- avoid implicit int
- don't misuse NULL
- don't arbitrarily mix signed and unsigned char

--- string.c.orig	1994-04-25 16:43:44.000000000 +0000
+++ string.c
@@ -3,7 +3,8 @@
 /* v1.00  1993 10/10	Ogasawara Hiroyuki		*/
 /*			oga@dgw.yz.yamagata-u.ac.jp	*/
 
-#define	NULL	0
+#include <stddef.h>
+#include "ackstring.h"
 
 unsigned char	__code_map[]= {
 	 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
@@ -24,18 +25,17 @@ unsigned char	__code_map[]= {
 	 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 0
 };
 
-unsigned char *
-SearchExtPosition( ptr )
-unsigned char	*ptr;
+char *
+SearchExtPosition( char *ptr )
 {
-	unsigned char	*ext= NULL;
+	char	*ext= NULL;
 #ifdef KANJINAME
-	int	kanji= NULL;
+	int	kanji= 0;
 	for(; *ptr ; ptr++ ){
 		if( kanji ){
-			kanji= NULL;
+			kanji= 0;
 		}else{
-			kanji= Iskanji( *ptr );
+			kanji= Iskanji( (unsigned char)*ptr );
 #else
 	for(; *ptr ; ptr++ ){
 		{
@@ -49,9 +49,12 @@ unsigned char	*ptr;
 	return	ext;
 }
 
-StrCmpAL( ptr1, ptr2 )
-unsigned char	*ptr1, *ptr2;
+int
+StrCmpAL( const char *ptr1X, const char *ptr2X )
 {
+	const unsigned char *ptr1 = (const unsigned char *)ptr1X;
+	const unsigned char *ptr2 = (const unsigned char *)ptr2X;
+
 	for(; *ptr1 && (*ptr1|0x20) == *ptr2 ; ptr1++, ptr2++ );
 	return	*ptr1-*ptr2;
 	/* '.'|0x20 -> '.' */
