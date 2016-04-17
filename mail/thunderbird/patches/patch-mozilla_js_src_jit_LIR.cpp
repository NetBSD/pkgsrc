$NetBSD: patch-mozilla_js_src_jit_LIR.cpp,v 1.2 2016/04/17 18:33:50 ryoon Exp $

--- mozilla/js/src/jit/LIR.cpp.orig	2016-04-07 21:33:24.000000000 +0000
+++ mozilla/js/src/jit/LIR.cpp
@@ -322,7 +322,7 @@ LNode::printName(GenericPrinter& out, Op
     const char* name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        out.printf("%c", tolower(name[i]));
+        out.printf("%c", tolower((unsigned char)name[i]));
 }
 
 void
