$NetBSD: patch-js_src_methodjit_MethodJIT.cpp,v 1.1.1.1 2012/03/15 08:58:28 ryoon Exp $

# This does not only apply to linux, but all ELF platforms (otherwise the
# generated code will not be PIC)

--- js/src/methodjit/MethodJIT.cpp.orig	2012-03-09 22:20:19.000000000 +0000
+++ js/src/methodjit/MethodJIT.cpp
@@ -171,7 +171,7 @@ SetVMFrameRegs(VMFrame &f)
 
 JS_STATIC_ASSERT(offsetof(FrameRegs, sp) == 0);
 
-#if defined(__linux__) && defined(JS_CPU_X64)
+#if defined(__ELF__) && defined(JS_CPU_X64)
 # define SYMBOL_STRING_RELOC(name) #name "@plt"
 #else
 # define SYMBOL_STRING_RELOC(name) SYMBOL_STRING(name)
