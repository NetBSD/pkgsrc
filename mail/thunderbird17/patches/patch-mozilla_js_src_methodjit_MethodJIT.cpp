$NetBSD: patch-mozilla_js_src_methodjit_MethodJIT.cpp,v 1.1 2013/11/13 13:27:45 ryoon Exp $

--- mozilla/js/src/methodjit/MethodJIT.cpp.orig	2012-08-25 00:31:13.000000000 +0000
+++ mozilla/js/src/methodjit/MethodJIT.cpp
@@ -135,7 +135,7 @@ PopActiveVMFrame(VMFrame &f)
 
 JS_STATIC_ASSERT(offsetof(FrameRegs, sp) == 0);
 
-#if defined(__linux__) && defined(JS_CPU_X64)
+#if defined(__ELF__) && defined(JS_CPU_X64)
 # define SYMBOL_STRING_RELOC(name) #name "@plt"
 #else
 # define SYMBOL_STRING_RELOC(name) SYMBOL_STRING(name)
