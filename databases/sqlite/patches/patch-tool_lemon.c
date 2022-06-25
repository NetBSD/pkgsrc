$NetBSD: patch-tool_lemon.c,v 1.2 2022/06/25 09:17:38 he Exp $

Avoid either undefined or implementation defined behaviour,
by making the base hash variable unsigned, so that we avoid
it ever going negative (as it did on powerpc).

--- tool/lemon.c.orig	2005-04-23 22:43:22.000000000 +0000
+++ tool/lemon.c
@@ -3016,7 +3016,7 @@ int mhflag;                 /* True if g
   int maxdtlength;          /* Maximum length of any ".datatype" field. */
   char *stddt;              /* Standardized name for a datatype */
   int i,j;                  /* Loop counters */
-  int hash;                 /* For hashing the name of a type */
+  unsigned int hash;        /* For hashing the name of a type */
   char *name;               /* Name of the parser */
 
   /* Allocate and initialize types[] and allocate stddt[] */
