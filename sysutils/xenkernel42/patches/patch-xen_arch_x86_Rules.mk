$NetBSD: patch-xen_arch_x86_Rules.mk,v 1.1 2013/06/13 21:49:59 joerg Exp $

--- xen/arch/x86/Rules.mk.orig	2013-03-25 13:28:19.000000000 +0000
+++ xen/arch/x86/Rules.mk
@@ -21,6 +21,7 @@ CFLAGS += -iwithprefix include -Werror -
 CFLAGS += -I$(BASEDIR)/include 
 CFLAGS += -I$(BASEDIR)/include/asm-x86/mach-generic
 CFLAGS += -I$(BASEDIR)/include/asm-x86/mach-default
+CFLAGS += $(EXTRA_CFLAGS)
 
 # Prevent floating-point variables from creeping into Xen.
 CFLAGS += -msoft-float
