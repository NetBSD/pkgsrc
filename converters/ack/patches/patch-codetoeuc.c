$NetBSD: patch-codetoeuc.c,v 1.1 2012/12/26 21:21:38 dholland Exp $

- declare own functions
- avoid implicit int

--- codetoeuc.c~	1994-03-23 21:57:34.000000000 +0000
+++ codetoeuc.c
@@ -4,9 +4,10 @@
 /*			oga@dgw.yz.yamagata-u.ac.jp	*/
 
 #include	"kanjicode.h"
+#include	"misc.h"
 
-CodeToEuc( code )
-unsigned int	code;
+unsigned int
+CodeToEuc( unsigned int code )
 {
 	unsigned int	hi=  code>>8;
 
