$NetBSD: patch-qemu-xen_dyngen-exec.h,v 1.1 2015/10/19 16:40:41 joerg Exp $

--- qemu-xen/dyngen-exec.h.orig	2015-10-09 22:41:38.000000000 +0000
+++ qemu-xen/dyngen-exec.h
@@ -19,6 +19,7 @@
 #if !defined(__DYNGEN_EXEC_H__)
 #define __DYNGEN_EXEC_H__
 
+#if !defined(__clang__)
 #if defined(CONFIG_TCG_INTERPRETER)
 /* The TCG interpreter does not need a special register AREG0,
  * but it is possible to use one by defining AREG0.
@@ -59,6 +60,7 @@
 #else
 #error unsupported CPU
 #endif
+#endif
 
 #if defined(AREG0)
 register CPUState *env asm(AREG0);
