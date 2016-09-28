$NetBSD: patch-src_v6__pcode.cxx,v 1.1 2016/09/28 10:00:27 kamil Exp $

Add NetBSD support.

--- src/v6_pcode.cxx.orig	2007-02-16 23:46:45.000000000 +0000
+++ src/v6_pcode.cxx
@@ -9204,6 +9204,9 @@ int G__dasm(FILE *fout,int isthrow)
 #elif defined(G__NONSCALARFPOS_QNX)
         fpos_t pos;
         pos._Off = (off_t)G__asm_inst[pc+3];
+#elif defined(__NetBSD__)
+        fpos_t pos;
+        pos._pos = (off_t)G__asm_inst[pc+3];
 #else
         fpos_t pos = (fpos_t)G__asm_inst[pc+3];
 #endif
