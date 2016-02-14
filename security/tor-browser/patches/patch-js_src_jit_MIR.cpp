$NetBSD: patch-js_src_jit_MIR.cpp,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- js/src/jit/MIR.cpp.orig	2015-05-04 00:43:27.000000000 +0000
+++ js/src/jit/MIR.cpp
@@ -71,7 +71,7 @@ MDefinition::PrintOpcodeName(FILE* fp, M
     const char* name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        fprintf(fp, "%c", tolower(name[i]));
+        fprintf(fp, "%c", tolower(((unsigned char)name[i])));
 }
 
 const Value&
