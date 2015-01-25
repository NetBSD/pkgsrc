$NetBSD: patch-libs_context_src_asm_make__ppc32__sysv__macho__gas.S,v 1.1 2015/01/25 11:26:50 pho Exp $

Fix build failure on PPC Darwin:

  darwin.compile.asm bin.v2/libs/context/build/darwin-4.5.3/release/link-static/threading-multi/asm/make_ppc32_sysv_macho_gas.o
  libs/context/src/asm/make_ppc32_sysv_macho_gas.S:85:Parameter syntax error (parameter 3)

--- libs/context/src/asm/make_ppc32_sysv_macho_gas.S.orig	2015-01-25 10:27:18.000000000 +0000
+++ libs/context/src/asm/make_ppc32_sysv_macho_gas.S
@@ -82,7 +82,7 @@ _make_fcontext:
     subi  r3, r3, 304
 
     ; third arg of make_fcontext() == address of context-function
-    stw  r5, 236(%r3)
+    stw  r5, 236(r3)
 
     ; load LR
     mflr  r0
