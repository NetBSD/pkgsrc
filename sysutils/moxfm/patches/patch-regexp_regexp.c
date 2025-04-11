$NetBSD: patch-regexp_regexp.c,v 1.1 2025/04/11 01:49:11 nia Exp $

Do not define own malloc prototype.

--- regexp/regexp.c.orig	2025-04-11 00:05:57.925516490 +0000
+++ regexp/regexp.c
@@ -29,6 +29,7 @@
  * regular-expression syntax might require a total rethink.
  */
 #include <stdio.h>
+#include <stdlib.h>
 #include "regexp.h"
 #include "regmagic.h"
 
@@ -200,7 +201,6 @@ char *exp;
 	register char *longest;
 	register int len;
 	int flags;
-	extern char *malloc();
 
 	if (exp == NULL)
 		FAIL("NULL argument");
