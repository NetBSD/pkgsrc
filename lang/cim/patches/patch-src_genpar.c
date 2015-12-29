$NetBSD: patch-src_genpar.c,v 1.2 2015/12/29 23:34:44 dholland Exp $

Avoid implicit int.
Use C89.

--- src/genpar.c.orig	2012-10-26 12:54:44.000000000 +0000
+++ src/genpar.c
@@ -1112,8 +1112,7 @@ genprocparam (re)
 /******************************************************************************
                                                       GENPREDEFPROCCALL      */
 
-genpredefproccall (re)
-     struct EXP *re;
+void genpredefproccall (struct EXP *re)
 {
   int i;
   /* Hvis danger = TRUE s} skal returverdien legges p} stakken */
