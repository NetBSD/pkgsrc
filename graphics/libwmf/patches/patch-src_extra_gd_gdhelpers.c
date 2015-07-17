$NetBSD: patch-src_extra_gd_gdhelpers.c,v 1.1 2015/07/17 12:33:47 sevan Exp $

CVE-2007-3472 - Integer overflow in gdImageCreateTrueColor function.

--- src/extra/gd/gdhelpers.c.orig	2015-07-16 23:34:21.000000000 +0000
+++ src/extra/gd/gdhelpers.c
@@ -2,6 +2,7 @@
 #include "gdhelpers.h"
 #include <stdlib.h>
 #include <string.h>
+#include <limits.h>
 
 /* TBB: gd_strtok_r is not portable; provide an implementation */
 
@@ -94,3 +95,18 @@ gdFree (void *ptr)
 {
   free (ptr);
 }
+
+int overflow2(int a, int b)
+{
+	if(a < 0 || b < 0) {
+		fprintf(stderr, "gd warning: one parameter to a memory allocation multiplication is negative, failing operation gracefully\n");
+		return 1;
+	}
+	if(b == 0)
+		return 0;
+	if(a > INT_MAX / b) {
+		fprintf(stderr, "gd warning: product of memory allocation multiplication would exceed INT_MAX, failing operation gracefully\n");
+		return 1;
+	}
+	return 0;
+}
