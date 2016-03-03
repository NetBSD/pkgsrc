$NetBSD: patch-src_language_parsec.h,v 1.1 2016/03/03 13:28:22 wiz Exp $

--- src/language/parsec.h.orig	2014-07-30 13:38:47.000000000 +0000
+++ src/language/parsec.h
@@ -203,7 +203,7 @@ newintnode(struct node_loc *loc)
   if (loc->end-loc->start<=(long)(1+LOG10_2*BITS_IN_LONG))
   {
     pari_sp ltop=avma;
-    GEN g=strtoi(loc->start);
+    GEN g=pari_strtoi(loc->start);
     long s;
     avma=ltop;
     if (signe(g)==0)      return newnode(Fsmall,0,-1,loc);
