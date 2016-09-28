$NetBSD: patch-src_Method.cxx,v 1.1 2016/09/28 10:00:27 kamil Exp $

Add NetBSD support.

--- src/Method.cxx.orig	2007-03-15 17:59:30.000000000 +0000
+++ src/Method.cxx
@@ -515,6 +515,8 @@ long Cint::G__MethodInfo::FilePosition()
       return((long)ifunc->pentry[index]->pos.__pos);
 #elif defined(G__NONSCALARFPOS_QNX)      
       return((long)ifunc->pentry[index]->pos._Off);
+#elif defined(__NetBSD__)
+      return((long)ifunc->pentry[index]->pos._pos);
 #else
       return((long)ifunc->pentry[index]->pos);
 #endif
