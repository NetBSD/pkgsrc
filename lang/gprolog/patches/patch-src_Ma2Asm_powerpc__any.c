$NetBSD: patch-src_Ma2Asm_powerpc__any.c,v 1.1 2020/12/12 02:01:57 gutteridge Exp $

Fix PowerPC build.

--- src/Ma2Asm/powerpc_any.c.orig	2015-01-13 18:00:19.000000000 +0000
+++ src/Ma2Asm/powerpc_any.c
@@ -1011,7 +1011,7 @@ Data_Start(char *initializer_fct)
   if (initializer_fct == NULL)
     return;
 
-#ifdef M_powerpc_linux
+#if defined(M_powerpc_linux) || defined(M_powerpc_bsd)
   Inst_Printf(".section", ".ctors,\"aw\",@progbits");
   Inst_Printf(".align", "2");
   Inst_Printf(".long", UN "%s", initializer_fct);
