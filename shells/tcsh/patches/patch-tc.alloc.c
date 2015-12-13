$NetBSD: patch-tc.alloc.c,v 1.1 2015/12/13 10:46:26 markd Exp $

Fix gcc5 optimization issue - from upstream.

--- tc.alloc.c.orig	2015-02-22 16:31:54.000000000 +0000
+++ tc.alloc.c
@@ -348,10 +348,13 @@ calloc(size_t i, size_t j)
 {
 #ifndef lint
     char *cp;
+    volatile size_t k;
 
     i *= j;
     cp = xmalloc(i);
-    memset(cp, 0, i);
+    /* Stop gcc 5.x from optimizing malloc+memset = calloc */
+    k = i;
+    memset(cp, 0, k);
 
     return ((memalign_t) cp);
 #else
