$NetBSD: patch-expr.c,v 1.1 2026/03/22 10:31:53 nia Exp $

Modern GCC no longer likes implicit int.

--- expr.c.orig	2026-03-22 10:02:38.635698881 +0000
+++ expr.c
@@ -81,7 +81,7 @@ Delnum(nx)
 /*
  * Findnum(n, v, e) - find or optionally enter number value
  */
-
+int
 Findnum(n, v, e)
 	unsigned char *n;		/* register name */
 	int v;				/* value */
@@ -129,7 +129,7 @@ Findnum(n, v, e)
 /*
  * Findparms(n) - find parameter registers
  */
-
+int
 Findparms(n)
 	unsigned char *n;		/* parameter name */
 {
@@ -150,7 +150,7 @@ Findparms(n)
 /*
  * Findscale(n, v, e) - find and optionally enter scaling factor value
  */
-
+int
 Findscale(n, v, e)
 	int n;				/* scaling factor name */
 	double v;			/* value */
