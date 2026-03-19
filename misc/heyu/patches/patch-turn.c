$NetBSD: patch-turn.c,v 1.1 2026/03/19 14:55:21 nia Exp $

Modern GCC no longer likes implicit int. ANSIfy.

--- turn.c.orig	2026-03-19 14:44:28.259446048 +0000
+++ turn.c
@@ -33,8 +33,7 @@ extern int usage(), dimstate(), xwrite()
 extern void parse_unit();
 extern unsigned int getunits();
 
-int c_turn(argc, argv)
-char *argv[];
+int c_turn(int argc, char *argv[])
 {
     register int n, x;
     unsigned int hcode, dim, bits, unit;
