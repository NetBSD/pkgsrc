$NetBSD: patch-include_sysemu_hw_accel.h,v 1.1 2021/03/06 11:19:34 reinoud Exp $

--- include/sysemu/hw_accel.h.orig	2020-12-08 16:59:44.000000000 +0000
+++ include/sysemu/hw_accel.h
@@ -16,6 +16,7 @@
 #include "sysemu/kvm.h"
 #include "sysemu/hvf.h"
 #include "sysemu/whpx.h"
+#include "sysemu/nvmm.h"
 
 void cpu_synchronize_state(CPUState *cpu);
 void cpu_synchronize_post_reset(CPUState *cpu);
