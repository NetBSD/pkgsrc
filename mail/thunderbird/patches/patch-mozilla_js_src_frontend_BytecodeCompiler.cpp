$NetBSD: patch-mozilla_js_src_frontend_BytecodeCompiler.cpp,v 1.3 2015/06/08 13:40:58 joerg Exp $

--- mozilla/js/src/frontend/BytecodeCompiler.cpp.orig	2015-05-07 18:53:49.000000000 +0000
+++ mozilla/js/src/frontend/BytecodeCompiler.cpp
@@ -544,7 +544,7 @@ CompileFunctionBody(JSContext* cx, Mutab
 
     RootedScriptSource sourceObject(cx, CreateScriptSourceObject(cx, options));
     if (!sourceObject)
-        return nullptr;
+        return false;
     ScriptSource* ss = sourceObject->source();
 
     SourceCompressionTask sct(cx);
