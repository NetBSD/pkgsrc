$NetBSD: patch-mozilla_js_src_jit_MIR.cpp,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/js/src/jit/MIR.cpp.orig	2015-06-08 17:49:25.000000000 +0000
+++ mozilla/js/src/jit/MIR.cpp
@@ -71,7 +71,7 @@ MDefinition::PrintOpcodeName(FILE* fp, M
     const char* name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        fprintf(fp, "%c", tolower(name[i]));
+        fprintf(fp, "%c", tolower(((unsigned char)name[i])));
 }
 
 const Value&
