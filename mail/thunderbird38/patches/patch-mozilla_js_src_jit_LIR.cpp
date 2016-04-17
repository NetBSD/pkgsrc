$NetBSD: patch-mozilla_js_src_jit_LIR.cpp,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/js/src/jit/LIR.cpp.orig	2015-06-08 17:49:25.000000000 +0000
+++ mozilla/js/src/jit/LIR.cpp
@@ -323,7 +323,7 @@ LNode::printName(FILE* fp, Opcode op)
     const char* name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        fprintf(fp, "%c", tolower(name[i]));
+        fprintf(fp, "%c", tolower(((unsigned char)name[i])));
 }
 
 void
