$NetBSD: patch-arch_bsd.xs,v 1.1 2021/12/18 15:07:01 prlw1 Exp $

UVM appeared since NetBSD 2.0.2.

--- arch/bsd.xs.orig	2006-09-16 14:32:56.000000000 +0000
+++ arch/bsd.xs
@@ -8,6 +8,9 @@ MODULE = Sys::MemInfo PACKAGE = Sys::Mem
 #include <stdio.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#ifdef NETBSD
+#include <uvm/uvm_extern.h>
+#endif
 
 void
 availkeys()
