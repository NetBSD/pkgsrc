$NetBSD: patch-hotspot_src_os__cpu_bsd__zero_vm_orderAccess__bsd__zero.inline.hpp,v 1.1 2015/02/21 10:44:14 tnn Exp $

ARM: Substitute Linux atomic ops with NetBSD atomic ops

--- hotspot/src/os_cpu/bsd_zero/vm/orderAccess_bsd_zero.inline.hpp.orig	2015-02-02 15:32:37.000000000 +0000
+++ hotspot/src/os_cpu/bsd_zero/vm/orderAccess_bsd_zero.inline.hpp
@@ -37,8 +37,13 @@
  * and gcc __sync_synchronize(); implementation does not use the kernel
  * helper for all gcc versions so it is unreliable to use as well.
  */
+#ifdef __NetBSD__
+#include <sys/atomic.h>
+#define __kernel_dmb membar_sync
+#else
 typedef void (__kernel_dmb_t) (void);
 #define __kernel_dmb (*(__kernel_dmb_t *) 0xffff0fa0)
+#endif
 
 #define FULL_MEM_BARRIER __kernel_dmb()
 #define READ_MEM_BARRIER __kernel_dmb()
