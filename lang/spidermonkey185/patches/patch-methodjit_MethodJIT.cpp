$NetBSD: patch-methodjit_MethodJIT.cpp,v 1.1 2020/04/13 19:19:37 joerg Exp $

Global "asm volatile" is considered a mistake now.

--- methodjit/MethodJIT.cpp.orig	2020-04-12 22:33:42.079089372 +0000
+++ methodjit/MethodJIT.cpp
@@ -189,7 +189,7 @@ JS_STATIC_ASSERT(offsetof(VMFrame, regs.
 JS_STATIC_ASSERT(JSVAL_TAG_MASK == 0xFFFF800000000000LL);
 JS_STATIC_ASSERT(JSVAL_PAYLOAD_MASK == 0x00007FFFFFFFFFFFLL);
 
-asm volatile (
+asm (
 ".text\n"
 ".globl " SYMBOL_STRING(JaegerTrampoline) "\n"
 SYMBOL_STRING(JaegerTrampoline) ":"       "\n"
@@ -236,7 +236,7 @@ SYMBOL_STRING(JaegerTrampoline) ":"     
     "jmp *0(%rsp)"                      "\n"
 );
 
-asm volatile (
+asm (
 ".text\n"
 ".globl " SYMBOL_STRING(JaegerTrampolineReturn) "\n"
 SYMBOL_STRING(JaegerTrampolineReturn) ":"       "\n"
@@ -256,7 +256,7 @@ SYMBOL_STRING(JaegerTrampolineReturn) ":
     "ret"                                "\n"
 );
 
-asm volatile (
+asm (
 ".text\n"
 ".globl " SYMBOL_STRING(JaegerThrowpoline)  "\n"
 SYMBOL_STRING(JaegerThrowpoline) ":"        "\n"
@@ -281,7 +281,7 @@ SYMBOL_STRING(JaegerThrowpoline) ":"    
 
 JS_STATIC_ASSERT(offsetof(VMFrame, regs.fp) == 0x38);
 
-asm volatile (
+asm (
 ".text\n"
 ".globl " SYMBOL_STRING(InjectJaegerReturn)   "\n"
 SYMBOL_STRING(InjectJaegerReturn) ":"         "\n"
@@ -309,7 +309,7 @@ SYMBOL_STRING(InjectJaegerReturn) ":"   
 JS_STATIC_ASSERT(offsetof(VMFrame, savedEBX) == 0x2c);
 JS_STATIC_ASSERT(offsetof(VMFrame, regs.fp) == 0x1C);
 
-asm volatile (
+asm (
 ".text\n"
 ".globl " SYMBOL_STRING(JaegerTrampoline) "\n"
 SYMBOL_STRING(JaegerTrampoline) ":"       "\n"
@@ -339,7 +339,7 @@ SYMBOL_STRING(JaegerTrampoline) ":"     
     "jmp *16(%ebp)"                      "\n"
 );
 
-asm volatile (
+asm (
 ".text\n"
 ".globl " SYMBOL_STRING(JaegerTrampolineReturn) "\n"
 SYMBOL_STRING(JaegerTrampolineReturn) ":" "\n"
@@ -357,7 +357,7 @@ SYMBOL_STRING(JaegerTrampolineReturn) ":
     "ret"                                "\n"
 );
 
-asm volatile (
+asm (
 ".text\n"
 ".globl " SYMBOL_STRING(JaegerThrowpoline)  "\n"
 SYMBOL_STRING(JaegerThrowpoline) ":"        "\n"
@@ -388,7 +388,7 @@ SYMBOL_STRING(JaegerThrowpoline) ":"    
 
 JS_STATIC_ASSERT(offsetof(VMFrame, regs.fp) == 0x1C);
 
-asm volatile (
+asm (
 ".text\n"
 ".globl " SYMBOL_STRING(InjectJaegerReturn)   "\n"
 SYMBOL_STRING(InjectJaegerReturn) ":"         "\n"
@@ -423,7 +423,7 @@ JS_STATIC_ASSERT(JSReturnReg_Type == JSC
 #define FUNCTION_HEADER_EXTRA
 #endif
 
-asm volatile (
+asm (
 ".text\n"
 FUNCTION_HEADER_EXTRA
 ".globl " SYMBOL_STRING(InjectJaegerReturn) "\n"
@@ -436,7 +436,7 @@ SYMBOL_STRING(InjectJaegerReturn) ":"   
     "bx  lr"                                "\n"
 );
 
-asm volatile (
+asm (
 ".text\n"
 FUNCTION_HEADER_EXTRA
 ".globl " SYMBOL_STRING(JaegerTrampoline)   "\n"
@@ -495,7 +495,7 @@ SYMBOL_STRING(JaegerTrampoline) ":"     
 "   bx     r4"                                  "\n"
 );
 
-asm volatile (
+asm (
 ".text\n"
 FUNCTION_HEADER_EXTRA
 ".globl " SYMBOL_STRING(JaegerTrampolineReturn)   "\n"
@@ -515,7 +515,7 @@ SYMBOL_STRING(JaegerTrampolineReturn) ":
 "   pop     {r4-r11,pc}"                    "\n"
 );
 
-asm volatile (
+asm (
 ".text\n"
 FUNCTION_HEADER_EXTRA
 ".globl " SYMBOL_STRING(JaegerThrowpoline)  "\n"
@@ -540,7 +540,7 @@ SYMBOL_STRING(JaegerThrowpoline) ":"    
 "   pop     {r4-r11,pc}"                    "\n"
 );
 
-asm volatile (
+asm (
 ".text\n"
 FUNCTION_HEADER_EXTRA
 ".globl " SYMBOL_STRING(JaegerStubVeneer)   "\n"
