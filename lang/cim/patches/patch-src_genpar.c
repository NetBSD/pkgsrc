$NetBSD: patch-src_genpar.c,v 1.1 2012/10/26 20:37:15 joerg Exp $

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
