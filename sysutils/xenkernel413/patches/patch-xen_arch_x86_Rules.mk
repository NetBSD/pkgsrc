$NetBSD: patch-xen_arch_x86_Rules.mk,v 1.1 2020/05/26 11:12:10 bouyer Exp $

--- xen/arch/x86/Rules.mk.orig	2018-04-17 19:21:31.000000000 +0200
+++ xen/arch/x86/Rules.mk	2018-04-23 13:31:24.000000000 +0200
@@ -8,6 +8,7 @@
 CFLAGS += -I$(BASEDIR)/include/asm-x86/mach-default
 CFLAGS += -DXEN_IMG_OFFSET=$(XEN_IMG_OFFSET)
 CFLAGS += '-D__OBJECT_LABEL__=$(subst /,$$,$(subst -,_,$(subst $(BASEDIR)/,,$(CURDIR))/$@))'
+CFLAGS += $(EXTRA_CFLAGS)
 
 # Prevent floating-point variables from creeping into Xen.
 CFLAGS += -msoft-float
