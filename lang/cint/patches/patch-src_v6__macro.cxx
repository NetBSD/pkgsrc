$NetBSD: patch-src_v6__macro.cxx,v 1.1 2016/09/28 10:00:27 kamil Exp $

Add NetBSD support.

--- src/v6_macro.cxx.orig	2006-11-23 13:34:01.000000000 +0000
+++ src/v6_macro.cxx
@@ -465,6 +465,9 @@ G__value G__execfuncmacro(char *item,int
 #elif defined(G__NONSCALARFPOS_QNX)
     if(call_pos._Off == callfuncmacro->call_pos._Off &&
        G__ifile.filenum == callfuncmacro->call_filenum) {
+#elif defined(__NetBSD__)
+    if(call_pos._pos == callfuncmacro->call_pos._pos &&
+       G__ifile.filenum == callfuncmacro->call_filenum) {
 #else
     if(call_pos == callfuncmacro->call_pos &&
        G__ifile.filenum == callfuncmacro->call_filenum) {
@@ -782,6 +785,9 @@ int G__execfuncmacro_noexec (char* macro
 #elif defined(G__NONSCALARFPOS_QNX)
     if(call_pos._Off == callfuncmacro->call_pos._Off &&
        G__ifile.filenum == callfuncmacro->call_filenum)       
+#elif defined(__NetBSD__)
+    if(call_pos._pos == callfuncmacro->call_pos._pos &&
+       G__ifile.filenum == callfuncmacro->call_filenum)
 #else
     if(call_pos == callfuncmacro->call_pos &&
        G__ifile.filenum == callfuncmacro->call_filenum)
