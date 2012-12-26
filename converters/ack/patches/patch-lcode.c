$NetBSD: patch-lcode.c,v 1.1 2012/12/26 21:21:38 dholland Exp $

- declare own functions
- declare void functions void

--- lcode.c.orig	1994-07-26 09:03:45.000000000 +0000
+++ lcode.c
@@ -5,10 +5,10 @@
 
 #include	"kanjicode.h"
 #include	"ackstring.h"
+#include	"misc.h"
 
-SjisEucCheck( ptr, len, cp )
-unsigned char	*ptr;
-T_KANJI		*cp;
+void
+SjisEucCheck( unsigned char *ptr, size_t len, T_KANJI *cp )
 {
 	unsigned char	*endp= ptr+len;
 	int		sjis= 0, euc= 0, step;
