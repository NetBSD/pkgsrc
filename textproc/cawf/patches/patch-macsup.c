$NetBSD: patch-macsup.c,v 1.1 2026/03/22 10:31:53 nia Exp $

Modern GCC no longer likes implicit int.

--- macsup.c.orig	2026-03-22 10:02:23.298568206 +0000
+++ macsup.c
@@ -101,7 +101,7 @@ Field(n, p, c)
  * return = Macrotab[] index or -1 if not found
  */
 
-
+int
 Findmacro(p, e)
 	unsigned char *p;	/* pointer to 2 character macro name  */
 	int e;			/* 0 = find, don't enter
