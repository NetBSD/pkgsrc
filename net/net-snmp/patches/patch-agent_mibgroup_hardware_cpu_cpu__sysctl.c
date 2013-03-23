$NetBSD: patch-agent_mibgroup_hardware_cpu_cpu__sysctl.c,v 1.1 2013/03/23 12:23:25 joerg Exp $

--- agent/mibgroup/hardware/cpu/cpu_sysctl.c.orig	2013-03-23 10:53:47.000000000 +0000
+++ agent/mibgroup/hardware/cpu/cpu_sysctl.c
@@ -24,6 +24,9 @@
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <sys/vmmeter.h>
+#ifdef HAVE_UVM_UVM_EXTERN_H
+#include <uvm/uvm_extern.h>
+#endif
 #ifdef HAVE_VM_VM_PARAM_H
 #include <vm/vm_param.h>
 #endif
