$NetBSD: patch-src_v6__parse.cxx,v 1.1 2016/09/28 10:00:27 kamil Exp $

Add NetBSD support.

--- src/v6_parse.cxx.orig	2007-03-15 17:59:30.000000000 +0000
+++ src/v6_parse.cxx
@@ -297,6 +297,8 @@ int G__ignore_catch()
     G__asm_inst[G__asm_cp+3]=(long)fpos1.__pos;
 #elif defined(G__NONSCALARFPOS_QNX)
     G__asm_inst[G__asm_cp+3]=(long)fpos1._Off;
+#elif defined(__NetBSD__)
+    G__asm_inst[G__asm_cp+3]=(long)fpos1._pos;
 #else
     G__asm_inst[G__asm_cp+3]=(long)fpos1;
 #endif
