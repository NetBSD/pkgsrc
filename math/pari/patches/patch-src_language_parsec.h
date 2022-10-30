$NetBSD: patch-src_language_parsec.h,v 1.2 2022/10/30 10:00:15 nros Exp $

* Don't conflict with NetBSDs strtoi function

--- src/language/parsec.h.orig	2022-07-27 16:29:32.000000000 +0000
+++ src/language/parsec.h
@@ -187,7 +187,7 @@ newintnode(struct node_loc *loc)
   if (loc->end-loc->start<=(long)(1+LOG10_2*BITS_IN_LONG))
   {
     pari_sp ltop=avma;
-    GEN g=strtoi(loc->start);
+    GEN g=pari_strtoi(loc->start);
     long s = itos_or_0(g), sg = signe(g);
     set_avma(ltop);
     if (sg==0 || s) return newnode(Fsmall,s,-1,loc);
