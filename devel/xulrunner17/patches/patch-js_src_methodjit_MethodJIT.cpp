$NetBSD: patch-js_src_methodjit_MethodJIT.cpp,v 1.1 2013/01/10 16:17:10 ryoon Exp $

# This does not only apply to linux, but all ELF platforms (otherwise the
# generated code will not be PIC)

--- js/src/methodjit/MethodJIT.cpp.orig	2012-08-24 22:55:40.000000000 +0000
+++ js/src/methodjit/MethodJIT.cpp
@@ -135,7 +135,7 @@ PopActiveVMFrame(VMFrame &f)
 
 JS_STATIC_ASSERT(offsetof(FrameRegs, sp) == 0);
 
-#if defined(__linux__) && defined(JS_CPU_X64)
+#if defined(__ELF__) && defined(JS_CPU_X64)
 # define SYMBOL_STRING_RELOC(name) #name "@plt"
 #else
 # define SYMBOL_STRING_RELOC(name) SYMBOL_STRING(name)
