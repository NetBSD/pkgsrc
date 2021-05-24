$NetBSD: patch-include_sysemu_hw__accel.h,v 1.4 2021/05/24 14:22:08 ryoon Exp $

--- include/sysemu/hw_accel.h.orig	2021-04-29 17:18:58.000000000 +0000
+++ include/sysemu/hw_accel.h
@@ -16,6 +16,7 @@
 #include "sysemu/kvm.h"
 #include "sysemu/hvf.h"
 #include "sysemu/whpx.h"
+#include "sysemu/nvmm.h"
 
 void cpu_synchronize_state(CPUState *cpu);
 void cpu_synchronize_post_reset(CPUState *cpu);
