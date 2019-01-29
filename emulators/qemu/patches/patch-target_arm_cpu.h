$NetBSD: patch-target_arm_cpu.h,v 1.1 2019/01/29 16:01:29 martin Exp $

Patch from upstream maintain (Peter Maydell) to fix NetBSD ATF tests
non-trapping FP exception detection.

--- target/arm/cpu.h.orig	2018-12-11 18:44:34.000000000 +0100
+++ target/arm/cpu.h	2019-01-29 15:44:39.081529725 +0100
@@ -1297,7 +1297,7 @@ void vfp_set_fpscr(CPUARMState *env, uin
  * we store the underlying state in fpscr and just mask on read/write.
  */
 #define FPSR_MASK 0xf800009f
-#define FPCR_MASK 0x07ff9f00
+#define FPCR_MASK 0x07ff0000
 
 #define FPCR_FZ16   (1 << 19)   /* ARMv8.2+, FP16 flush-to-zero */
 #define FPCR_FZ     (1 << 24)   /* Flush-to-zero enable bit */
