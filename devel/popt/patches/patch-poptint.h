$NetBSD: patch-poptint.h,v 1.2 2019/05/05 23:16:06 rjs Exp $

Don't include stdint.h if it does not exist.  Fixes PR#44770

--- poptint.h.orig	2010-01-19 00:39:10.000000000 +0000
+++ poptint.h
@@ -9,7 +9,13 @@
 #ifndef H_POPTINT
 #define H_POPTINT
 
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
+
+#ifdef HAVE_STDLIB_H
+#include <stdlib.h>
+#endif
 
 /**
  * Wrapper to free(3), hides const compilation noise, permit NULL, return NULL.
