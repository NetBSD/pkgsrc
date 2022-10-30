$NetBSD: patch-src_basemath_nflist.c,v 1.1 2022/10/30 10:00:15 nros Exp $

* Don't conflict with NetBSDs strtoi function

--- src/basemath/nflist.c.orig	2022-09-16 17:16:27.000000000 +0000
+++ src/basemath/nflist.c
@@ -5057,7 +5057,7 @@ grouptranslate(const char *g, long *t, i
 
   if (QT)
   {
-    r = *g; ell = itos( strtoi(g + 1) );
+    r = *g; ell = itos( pari_strtoi(g + 1) );
     if (ell < 0) return 0;
     if (r == 'A') { *t = -2; return ell; }
     if (r == 'S') { *t = -1; return ell; }
@@ -5094,7 +5094,7 @@ grouptranslate(const char *g, long *t, i
     if (!strcmp(g, "C11")) { *t = 1; return 11; }
     if (!strcmp(g, "D11")) { *t = 2; return 11; }
   }
-  r = *g; ell = itos( strtoi(g + 1) );
+  r = *g; ell = itos( pari_strtoi(g + 1) );
   if (ell >= 8 && uisprime(ell))
   {
     if (r == 'C') { *t = 1; return ell; }
