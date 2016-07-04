$NetBSD: patch-xen_arch_x86_Rules.mk,v 1.1.1.1 2016/07/04 07:25:14 jnemeth Exp $

--- xen/arch/x86/Rules.mk.orig	2015-01-12 17:53:24.000000000 +0100
+++ xen/arch/x86/Rules.mk	2015-01-19 12:29:14.000000000 +0100
@@ -24,6 +24,7 @@
 CFLAGS += -I$(BASEDIR)/include 
 CFLAGS += -I$(BASEDIR)/include/asm-x86/mach-generic
 CFLAGS += -I$(BASEDIR)/include/asm-x86/mach-default
+CFLAGS += $(EXTRA_CFLAGS)
 
 # Prevent floating-point variables from creeping into Xen.
 CFLAGS += -msoft-float
