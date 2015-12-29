$NetBSD: patch-src_genexp.c,v 1.2 2015/12/29 23:34:44 dholland Exp $

Avoid implicit int.
Use C89.
Use standard headers.

--- src/genexp.c.orig	2012-10-26 13:04:17.000000000 +0000
+++ src/genexp.c
@@ -20,6 +20,8 @@
 #include "gen.h"
 #include "extspec.h"
 
+#include <string.h>
+
 int stack;
 static int anttext;
 int inthunk;			/* Brukes i forbindelse med uttrykk i
@@ -196,8 +198,7 @@ genmodulemark(maintimestamp) char *maint
 /******************************************************************************
                                                                 GENVALUE     */
 
-genvalue (re)
-     struct EXP *re;
+void genvalue (struct EXP *re)
 {
   struct EXP *rex;
   static struct EXP *ree;
