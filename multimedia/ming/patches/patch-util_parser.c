$NetBSD: patch-util_parser.c,v 1.1 2018/11/23 12:13:19 jperkin Exp $

Need limits.h for INT_MAX and provide MAX compat macro.

--- util/parser.c.orig	2017-04-07 08:12:56.000000000 +0000
+++ util/parser.c
@@ -18,6 +18,7 @@
  *
  ****************************************************************************/
 
+#include <limits.h>
 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -51,6 +52,10 @@ void silentSkipBytes(FILE *f, int length
 	printf("skipping %i bytes\n", length); \
         readBytes(f, length);
 
+#ifndef MAX
+#define MAX(a, b) ((a > b) ? a : b)
+#endif
+
 /* Parse Basic Flash types */
 
 void
