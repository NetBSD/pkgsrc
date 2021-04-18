$NetBSD: patch-xen_arch_x86_Rules.mk,v 1.1 2021/04/18 12:31:26 bouyer Exp $

--- xen/arch/x86/Rules.mk.orig	2020-12-08 15:28:32.000000000 +0100
+++ xen/arch/x86/Rules.mk	2020-12-08 17:27:58.740162095 +0100
@@ -8,3 +8,5 @@
 endif
 c_flags += $(object_label_flags) $(CFLAGS-stack-boundary)
 a_flags += $(object_label_flags) $(CFLAGS-stack-boundary)
+
+c_flags += $(EXTRA_CFLAGS)
