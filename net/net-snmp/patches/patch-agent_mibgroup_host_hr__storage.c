$NetBSD: patch-agent_mibgroup_host_hr__storage.c,v 1.1 2022/10/18 12:01:52 adam Exp $

--- agent/mibgroup/host/hr_storage.c.orig	2012-10-09 22:28:58.000000000 +0000
+++ agent/mibgroup/host/hr_storage.c
@@ -69,6 +69,13 @@
 #endif
 #endif                          /* vm/vm.h */
 #endif                          /* sys/vm.h */
+#if HAVE_SYS_POOL_H
+#if defined(MBPOOL_SYMBOL) && defined(MCLPOOL_SYMBOL)
+#define __POOL_EXPOSE
+#include <sys/pool.h>
+#else
+#undef HAVE_SYS_POOL_H
+#endif
 #if defined(HAVE_UVM_UVM_PARAM_H) && defined(HAVE_UVM_UVM_EXTERN_H)
 #include <uvm/uvm_param.h>
 #include <uvm/uvm_extern.h>
@@ -76,20 +83,13 @@
 #include <vm/vm_param.h>
 #include <vm/vm_extern.h>
 #endif
+#endif
 #if HAVE_KVM_H
 #include <kvm.h>
 #endif
 #if HAVE_FCNTL_H
 #include <fcntl.h>
 #endif
-#if HAVE_SYS_POOL_H
-#if defined(MBPOOL_SYMBOL) && defined(MCLPOOL_SYMBOL)
-#define __POOL_EXPOSE
-#include <sys/pool.h>
-#else
-#undef HAVE_SYS_POOL_H
-#endif
-#endif
 #if HAVE_SYS_MBUF_H
 #include <sys/mbuf.h>
 #endif
