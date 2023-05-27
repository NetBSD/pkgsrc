$NetBSD: patch-arch_bsd.xs,v 1.2 2023/05/27 11:58:32 gdt Exp $

Add uvm header on NetBSD.

Sent to maintainer via email 20220527.

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
