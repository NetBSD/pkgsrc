$NetBSD: patch-xen_arch_arm_xen.lds.S,v 1.1 2017/05/07 21:21:01 joerg Exp $

--- xen/arch/arm/xen.lds.S.orig	2016-06-20 12:08:22.000000000 +0000
+++ xen/arch/arm/xen.lds.S
@@ -110,6 +110,7 @@ SECTIONS
   . = ALIGN(PAGE_SIZE);
   .init.data : {
        *(.init.rodata)
+       *(.init.rodata.rel)
        *(.init.rodata.str*)
        *(.init.data)
        *(.init.data.rel)
