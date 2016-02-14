$NetBSD: patch-js_src_jit-LIR.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- js/src/jit/LIR.cpp.orig	2015-05-04 00:43:27.000000000 +0000
+++ js/src/jit/LIR.cpp
@@ -323,7 +323,7 @@ LNode::printName(FILE* fp, Opcode op)
     const char* name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        fprintf(fp, "%c", tolower(name[i]));
+        fprintf(fp, "%c", tolower(((unsigned char)name[i])));
 }
 
 void
