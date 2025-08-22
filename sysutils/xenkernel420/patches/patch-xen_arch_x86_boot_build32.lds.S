$NetBSD: patch-xen_arch_x86_boot_build32.lds.S,v 1.1 2025/08/22 09:00:11 bouyer Exp $
linux's toolchain doesn't generate a .eh_frame section but NetBSD does.
remove it.

--- xen/arch/x86/boot/build32.lds.S.orig	2025-08-21 12:51:20.500258990 +0200
+++ xen/arch/x86/boot/build32.lds.S	2025-08-21 12:51:25.633737534 +0200
@@ -65,6 +65,7 @@
        *(.comment)
        *(.comment.*)
        *(.note.*)
+       *(.eh_frame)
   }
   .shstrtab : {
        *(.shstrtab)
