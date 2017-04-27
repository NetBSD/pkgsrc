$NetBSD: patch-mozilla_js_src_jit_MIR.cpp,v 1.1 2017/04/27 13:38:19 ryoon Exp $

--- mozilla/js/src/jit/MIR.cpp.orig	2016-04-07 21:33:24.000000000 +0000
+++ mozilla/js/src/jit/MIR.cpp
@@ -75,7 +75,7 @@ MDefinition::PrintOpcodeName(GenericPrin
     const char* name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        out.printf("%c", tolower(name[i]));
+        out.printf("%c", tolower((unsigned char)name[i]));
 }
 
 const Value&
