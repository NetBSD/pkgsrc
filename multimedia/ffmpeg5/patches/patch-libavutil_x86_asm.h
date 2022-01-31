$NetBSD: patch-libavutil_x86_asm.h,v 1.1 2022/01/31 23:16:41 ryoon Exp $

Avoid SunOS regset.h definition for REG_SP

--- libavutil/x86/asm.h.orig	2016-10-28 18:31:25.000000000 +0000
+++ libavutil/x86/asm.h
@@ -27,6 +27,11 @@
 typedef struct xmm_reg { uint64_t a, b; } xmm_reg;
 typedef struct ymm_reg { uint64_t a, b, c, d; } ymm_reg;
 
+/* avoid SunOS regset.h definition for REG_SP */
+#if defined (__sun) && defined (REG_SP)
+#undef REG_SP
+#endif
+
 #if ARCH_X86_64
 #    define FF_OPSIZE "q"
 #    define FF_REG_a "rax"
