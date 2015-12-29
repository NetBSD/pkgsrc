$NetBSD: patch-src_expchecker.c,v 1.2 2015/12/29 23:34:44 dholland Exp $

Avoid implicit int.
Use C89.

--- src/expchecker.c.orig	2012-10-26 13:06:29.000000000 +0000
+++ src/expchecker.c
@@ -237,9 +237,7 @@ static sametype (rel, rer)
 /******************************************************************************
                                                                ARGUMENTERROR */
 
-static argumenterror (melding, re)
-     int melding;
-     struct EXP *re;
+static void argumenterror (int melding, struct EXP *re)
 {
   int i = 1;
   if (TYPE == TERROR)
