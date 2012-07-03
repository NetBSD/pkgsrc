$NetBSD: patch-symbol.c,v 1.1 2012/07/03 18:13:26 joerg Exp $

--- symbol.c.orig	2012-07-03 10:49:15.000000000 +0000
+++ symbol.c
@@ -20,6 +20,10 @@
  *	January, 1990.
  *
  */
+#include <string.h>
+#include <stdlib.h>
+
+void error(const char *, ...);
 
 #include "as31.h"
 #define NULL		(0)
@@ -149,7 +153,7 @@ static unsigned char clr[]=	{ 0xe4, 0xc3
 static unsigned char cpl[]=	{ 0xf4, 0xb3, 0xb2 };
 static unsigned char da[]=	{ 0xd4 };
 static unsigned char dec[]=	{ 0x14, 0x18, 0x15, 0x16 };
-static unsigned char div[]=	{ 0x84 };
+static unsigned char divop[]=	{ 0x84 };
 static unsigned char djnz[]=	{ 0xd8, 0xd5 };
 static unsigned char inc[]=	{ 0x04, 0x08, 0x05, 0x06, 0xa3 };
 static unsigned char jb[]=	{ 0x20 };
@@ -216,7 +220,7 @@ static struct opcode optable[] = {
 	{"cpl",		CPL,	cpl		},
 	{"da",		DA,	da		},
 	{"dec",		DEC,	dec		},
-	{"div",		DIV,	div		},
+	{"div",		DIV,	divop		},
 	{"djnz",	DJNZ,	djnz		},
 	{"dptr",	DPTR,	NULL		},
 	{"end",		D_END,	NULL		},
@@ -339,7 +343,7 @@ struct symbol *looksym(s)
 char *s;
 {
 	register struct symbol *ptr,*prev;
-	char *malloc(),*p;
+	char *p;
 	register int hv;
 
 	hv = hash(s);
