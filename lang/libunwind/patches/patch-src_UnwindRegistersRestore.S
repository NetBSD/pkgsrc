$NetBSD: patch-src_UnwindRegistersRestore.S,v 1.1 2020/10/18 17:06:35 he Exp $

Gcc doesn't define __ppc__, but defines __powerpc__ on NetBSD/powerpc.

--- src/UnwindRegistersRestore.S.orig	2020-07-07 16:21:37.000000000 +0000
+++ src/UnwindRegistersRestore.S
@@ -392,7 +392,7 @@ Lnovec:
   PPC64_LR(3)
   bctr
 
-#elif defined(__ppc__)
+#elif defined(__ppc__) || defined(__powerpc__)
 
 DEFINE_LIBUNWIND_FUNCTION(_ZN9libunwind13Registers_ppc6jumptoEv)
 //
