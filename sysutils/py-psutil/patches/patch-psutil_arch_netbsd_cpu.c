$NetBSD: patch-psutil_arch_netbsd_cpu.c,v 1.1 2023/04/18 22:11:08 wiz Exp $

Add missing header.

--- psutil/arch/netbsd/cpu.c.orig	2023-04-17 15:01:41.000000000 +0000
+++ psutil/arch/netbsd/cpu.c
@@ -6,6 +6,7 @@
  */
 
 #include <Python.h>
+#include <sys/sched.h>
 #include <sys/sysctl.h>
 #include <uvm/uvm_extern.h>
 
