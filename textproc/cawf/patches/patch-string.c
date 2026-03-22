$NetBSD: patch-string.c,v 1.1 2026/03/22 10:31:53 nia Exp $

Modern GCC no longer likes implicit int.

--- string.c.orig	2026-03-22 10:01:14.968205414 +0000
+++ string.c
@@ -37,7 +37,7 @@ _PROTOTYPE(static void Setroman,(void));
 /*
  * Asmname(s, c) - assemble name
  */
-
+int
 Asmname(s, c)
 	unsigned char *s;		/* pointer to name */
 	unsigned char *c;		/* code destination (c[3]) */
@@ -92,7 +92,7 @@ Endword()
  * Findchar(nm, l, s, e) - find special character definition and
  *			   optionally enter it
  */
-
+int
 Findchar(nm, l, s, e)
 	unsigned char *nm;		/* character name */
 	int l;				/* effective length */
@@ -146,7 +146,7 @@ new_char:
 /*
  * Findhy(s, l, e) - find and optionally enter hyphen
  */
-
+int
 Findhy(s, l, e)
 	unsigned char *s;		/* value string */
 	int l;				/* equivalent length */
@@ -270,7 +270,7 @@ Setroman()
 /*
  * Str2word(s, len) - copy len characters from string to Word[]
  */
-
+int
 Str2word(s, len)
 	unsigned char *s;
 	int len;
