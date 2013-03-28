$NetBSD: patch-g3_g3cat.c,v 1.1 2013/03/28 21:17:57 joerg Exp $

--- g3/g3cat.c.orig	2013-03-28 20:08:27.000000000 +0000
+++ g3/g3cat.c
@@ -44,7 +44,7 @@ static int b_written = 0;		/* bytes of a
 					/* written */
 
 #ifdef __GNUC__
-inline
+static inline
 #endif
 void putcode _P2( (code, len), int code, int len )
 {
@@ -67,7 +67,7 @@ void putcode _P2( (code, len), int code,
 }
 
 #ifdef __GNUC__
-inline
+static inline
 #endif
 void putwhitespan _P1( (l), int l )
 {
@@ -98,7 +98,7 @@ void putwhitespan _P1( (l), int l )
 }
 
 #ifdef __GNUC__
-inline
+static inline
 #endif
 void putblackspan _P1( (l), int l )
 {
@@ -129,7 +129,7 @@ void putblackspan _P1( (l), int l )
 }
 
 #ifdef __GNUC__
-inline
+static inline
 #endif
 void puteol _P0( void )			/* write byte-aligned EOL */
 {
