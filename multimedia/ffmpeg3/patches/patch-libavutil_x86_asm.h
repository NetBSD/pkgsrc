$NetBSD: patch-libavutil_x86_asm.h,v 1.1 2016/03/05 08:52:23 ryoon Exp $

avoid SunOS regset.h definition for REG_SP

--- libavutil/x86/asm.h.orig	2016-01-15 16:58:37.000000000 +0000
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
 #    define OPSIZE "q"
 #    define REG_a "rax"
