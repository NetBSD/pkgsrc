$NetBSD: patch-ffmpeg_libavutil_x86_asm.h,v 1.1 2015/11/21 09:47:23 leot Exp $

avoid SunOS regset.h definition for REG_SP

--- ffmpeg/libavutil/x86/asm.h.orig	2014-08-17 13:33:17.000000000 +0000
+++ ffmpeg/libavutil/x86/asm.h
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
