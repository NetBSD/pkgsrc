$NetBSD: patch-target_arm_helper.c,v 1.1 2019/01/31 13:39:10 martin Exp $

Upstream fix for arm/aarch64 FPU exception handling
test failures in the NetBSD ATF test suit.

--- target/arm/helper.c.orig	2018-12-11 18:44:34.000000000 +0100
+++ target/arm/helper.c	2019-01-31 14:29:37.050410598 +0100
@@ -11747,6 +11747,12 @@
         val &= ~FPCR_FZ16;
     }
 
+    /*
+     * We don't implement trapped exception handling, so the
+     * trap enable bits are all RAZ/WI (not RES0!)
+     */
+    val &= ~(FPCR_IDE | FPCR_IXE | FPCR_UFE | FPCR_OFE | FPCR_DZE | FPCR_IOE);
+
     changed = env->vfp.xregs[ARM_VFP_FPSCR];
     env->vfp.xregs[ARM_VFP_FPSCR] = (val & 0xffc8ffff);
     env->vfp.vec_len = (val >> 16) & 7;
