$NetBSD: patch-g3_pbm2g3.c,v 1.1 2013/03/28 21:17:57 joerg Exp $

--- g3/pbm2g3.c.orig	2013-03-28 20:08:30.000000000 +0000
+++ g3/pbm2g3.c
@@ -40,7 +40,7 @@ static unsigned int out_hibit = 0;
 static int out_byte_tab[ 256 ];			/* for g3 byte reversal */
 
 #ifdef __GNUC__
-inline
+static inline
 #endif
 void putcode _P2( (code, len), int code, int len )
 {
@@ -60,7 +60,7 @@ void putcode _P2( (code, len), int code,
 }
 
 #ifdef __GNUC__
-inline
+static inline
 #endif
 void puteol _P0( void )			/* write byte-aligned EOL */
 {
@@ -69,7 +69,7 @@ void puteol _P0( void )			/* write byte-
 }
 
 #ifdef __GNUC__
-inline
+static inline
 #endif
 void putwhitespan _P1( (l), int l )
 {
@@ -100,7 +100,7 @@ void putwhitespan _P1( (l), int l )
 }
 
 #ifdef __GNUC__
-inline
+static inline
 #endif
 void putblackspan _P1( (l), int l )
 {
