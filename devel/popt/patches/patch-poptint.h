$NetBSD: patch-poptint.h,v 1.1 2011/04/01 21:28:32 tez Exp $

Don't include stdint.h if it does not exist.  Fixes PR#44770

--- poptint.h.orig	2011-04-01 21:07:17.593937200 +0000
+++ poptint.h
@@ -9,7 +9,9 @@
 #ifndef H_POPTINT
 #define H_POPTINT
 
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 /**
  * Wrapper to free(3), hides const compilation noise, permit NULL, return NULL.
