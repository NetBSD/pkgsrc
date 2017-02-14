$NetBSD: patch-xen_arch_x86_xen.lds.S,v 1.1 2017/02/14 21:38:34 joerg Exp $

From e0a97098e20d8fe334b76b37dd6fb0a358a6953c.

--- xen/arch/x86/xen.lds.S.orig	2017-02-10 22:45:18.382878546 +0000
+++ xen/arch/x86/xen.lds.S
@@ -166,7 +166,7 @@ SECTIONS
        __bss_start = .;
        *(.bss.stack_aligned)
        . = ALIGN(PAGE_SIZE);
-       *(.bss.page_aligned)
+       *(.bss.page_aligned*)
        *(.bss)
        . = ALIGN(SMP_CACHE_BYTES);
        __per_cpu_start = .;
