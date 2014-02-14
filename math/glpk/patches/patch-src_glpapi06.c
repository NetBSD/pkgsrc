$NetBSD: patch-src_glpapi06.c,v 1.1 2014/02/14 09:25:49 adam Exp $

Function should return a value.

--- src/glpapi06.c.orig	2014-02-14 09:20:28.000000000 +0000
+++ src/glpapi06.c
@@ -815,7 +815,7 @@ int glp_get_it_cnt(glp_prob *P)
 int glp_set_it_cnt(glp_prob *P, int it_cnt)
 {     /* set simplex solver iteration count */
       P->it_cnt = it_cnt;
-      return;
+      return P->it_cnt;
 }
 #endif
 
