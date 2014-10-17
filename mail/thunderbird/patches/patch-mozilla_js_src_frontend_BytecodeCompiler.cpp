$NetBSD: patch-mozilla_js_src_frontend_BytecodeCompiler.cpp,v 1.1 2014/10/17 16:47:22 joerg Exp $

--- mozilla/js/src/frontend/BytecodeCompiler.cpp.orig	2014-10-17 09:17:47.000000000 +0000
+++ mozilla/js/src/frontend/BytecodeCompiler.cpp
@@ -544,7 +544,7 @@ CompileFunctionBody(JSContext *cx, Mutab
 
     RootedScriptSource sourceObject(cx, CreateScriptSourceObject(cx, options));
     if (!sourceObject)
-        return nullptr;
+        return false;
     ScriptSource *ss = sourceObject->source();
 
     SourceCompressionTask sct(cx);
