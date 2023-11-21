$NetBSD: patch-xen_arch_x86_Rules.mk,v 1.1 2023/11/21 11:38:26 bouyer Exp $

--- xen/arch/x86/Rules.mk.orig	2022-11-15 09:03:34.000000000 +0100
+++ xen/arch/x86/Rules.mk	2022-12-14 21:22:01.302860156 +0100
@@ -8,3 +8,5 @@
 endif
 c_flags += $(object_label_flags) $(CFLAGS_stack_boundary)
 a_flags += $(object_label_flags) $(CFLAGS_stack_boundary)
+
+c_flags += $(EXTRA_CFLAGS)
