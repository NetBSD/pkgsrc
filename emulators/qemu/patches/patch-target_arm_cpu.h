$NetBSD: patch-target_arm_cpu.h,v 1.2 2019/01/31 13:39:10 martin Exp $

Upstream fix for arm/aarch64 FPU exception handling
test failures in the NetBSD ATF test suit.

--- target/arm/cpu.h.orig	2018-12-11 18:44:34.000000000 +0100
+++ target/arm/cpu.h	2019-01-31 14:29:37.037792781 +0100
@@ -1299,6 +1299,12 @@ void vfp_set_fpscr(CPUARMState *env, uin
 #define FPSR_MASK 0xf800009f
 #define FPCR_MASK 0x07ff9f00
 
+#define FPCR_IOE    (1 << 8)    /* Invalid Operation exception trap enable */
+#define FPCR_DZE    (1 << 9)    /* Divide by Zero exception trap enable */
+#define FPCR_OFE    (1 << 10)   /* Overflow exception trap enable */
+#define FPCR_UFE    (1 << 11)   /* Underflow exception trap enable */
+#define FPCR_IXE    (1 << 12)   /* Inexact exception trap enable */
+#define FPCR_IDE    (1 << 15)   /* Input Denormal exception trap enable */
 #define FPCR_FZ16   (1 << 19)   /* ARMv8.2+, FP16 flush-to-zero */
 #define FPCR_FZ     (1 << 24)   /* Flush-to-zero enable bit */
 #define FPCR_DN     (1 << 25)   /* Default NaN enable bit */
