$NetBSD: patch-codetojis.c,v 1.1 2012/12/26 21:21:38 dholland Exp $

- declare own functions
- avoid implicit int
- silence warnings about assignments in conditionals

--- codetojis.c~	1994-04-19 07:05:42.000000000 +0000
+++ codetojis.c
@@ -4,6 +4,7 @@
 /*			oga@dgw.yz.yamagata-u.ac.jp	*/
 
 #include	"kanjicode.h"
+#include	"misc.h"
 
 static char	*kinmode[]= {
 		"\033(J",	/* JISX 201-1976 roma */
@@ -22,7 +23,8 @@ static int	kanjimode= KANJI,
 		kanamode=  KANA,
 		komode= ROMA;
 
-SetJisMode( mode )
+void
+SetJisMode( int mode )
 {
 	kanjimode=	  mode & 1 ? QKANJI : KANJI;
 	komode= romamode= mode & 2 ? ASCII  : ROMA;
@@ -32,8 +34,7 @@ SetJisMode( mode )
 }
 
 static void
-putmode( km )
-int	km;
+putmode( int km )
 {
 	if( komode != km ){
 		char	*p;
@@ -43,6 +44,7 @@ int	km;
 	}
 }
 
+unsigned int
 CodeToJis( code )
 unsigned int	code;
 {
@@ -56,7 +58,8 @@ unsigned int	code;
 	return	code & 0x7f;
 }
 
-setjismode()
+void
+setjismode(void)
 {
 	putmode( romamode );
 }
