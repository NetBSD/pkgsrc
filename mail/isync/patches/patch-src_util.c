$NetBSD: patch-src_util.c,v 1.1 2026/05/14 14:38:05 ktnb Exp $

Don't crash on 3 byte UTF-8 folder names

--- src/util.c.orig	2026-05-14 14:26:43.676943197 +0000
+++ src/util.c
@@ -477,7 +477,7 @@ to_upper( char *str, uint len )
 to_upper( char *str, uint len )
 {
 	for (uint i = 0; i < len; i++)
-		str[i] = toupper( str[i] );
+		str[i] = toupper( (unsigned char)str[i] );
 }
 
 int
@@ -492,7 +492,7 @@ equals_upper_impl( const char *str, const char *cmp, u
 equals_upper_impl( const char *str, const char *cmp, uint cmpl )
 {
 	for (uint i = 0; i < cmpl; i++)
-		if (toupper( str[i] ) != cmp[i])
+		if (toupper( (unsigned char)str[i] ) != cmp[i])
 			return 0;
 	return 1;
 }
