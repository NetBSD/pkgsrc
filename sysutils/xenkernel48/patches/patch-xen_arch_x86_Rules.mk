$NetBSD: patch-xen_arch_x86_Rules.mk,v 1.1 2017/03/30 09:15:09 bouyer Exp $

--- ./xen/arch/x86/Rules.mk.orig	2016-12-05 13:03:27.000000000 +0100
+++ ./xen/arch/x86/Rules.mk	2017-03-21 16:59:28.000000000 +0100
@@ -5,6 +5,7 @@
 CFLAGS += -I$(BASEDIR)/include/asm-x86/mach-generic
 CFLAGS += -I$(BASEDIR)/include/asm-x86/mach-default
 CFLAGS += '-D__OBJECT_LABEL__=$(subst /,$$,$(subst -,_,$(subst $(BASEDIR)/,,$(CURDIR))/$@))'
+CFLAGS += $(EXTRA_CFLAGS)
 
 # Prevent floating-point variables from creeping into Xen.
 CFLAGS += -msoft-float
