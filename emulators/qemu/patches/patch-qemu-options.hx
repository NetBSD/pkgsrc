$NetBSD: patch-qemu-options.hx,v 1.1 2020/02/06 16:46:17 kamil Exp $

Add NVMM support.

--- qemu-options.hx.orig	2019-12-12 18:20:48.000000000 +0000
+++ qemu-options.hx
@@ -31,7 +31,7 @@ DEF("machine", HAS_ARG, QEMU_OPTION_mach
     "-machine [type=]name[,prop[=value][,...]]\n"
     "                selects emulated machine ('-machine help' for list)\n"
     "                property accel=accel1[:accel2[:...]] selects accelerator\n"
-    "                supported accelerators are kvm, xen, hax, hvf, whpx or tcg (default: tcg)\n"
+    "                supported accelerators are kvm, xen, hax, hvf, nvmm, whpx or tcg (default: tcg)\n"
     "                kernel_irqchip=on|off|split controls accelerated irqchip support (default=off)\n"
     "                vmport=on|off|auto controls emulation of vmport (default: auto)\n"
     "                kvm_shadow_mem=size of KVM shadow MMU in bytes\n"
@@ -66,9 +66,9 @@ Supported machine properties are:
 @table @option
 @item accel=@var{accels1}[:@var{accels2}[:...]]
 This is used to enable an accelerator. Depending on the target architecture,
-kvm, xen, hax, hvf, whpx or tcg can be available. By default, tcg is used. If there is
-more than one accelerator specified, the next one is used if the previous one
-fails to initialize.
+kvm, xen, hax, hvf, nvmm, whpx or tcg can be available. By default, tcg is used.
+If there is more than one accelerator specified, the next one is used if the
+previous one fails to initialize.
 @item kernel_irqchip=on|off
 Controls in-kernel irqchip support for the chosen accelerator when available.
 @item gfx_passthru=on|off
@@ -119,15 +119,15 @@ ETEXI
 
 DEF("accel", HAS_ARG, QEMU_OPTION_accel,
     "-accel [accel=]accelerator[,thread=single|multi]\n"
-    "                select accelerator (kvm, xen, hax, hvf, whpx or tcg; use 'help' for a list)\n"
+    "                select accelerator (kvm, xen, hax, hvf, nvmm, whpx or tcg; use 'help' for a list)\n"
     "                thread=single|multi (enable multi-threaded TCG)\n", QEMU_ARCH_ALL)
 STEXI
 @item -accel @var{name}[,prop=@var{value}[,...]]
 @findex -accel
 This is used to enable an accelerator. Depending on the target architecture,
-kvm, xen, hax, hvf, whpx or tcg can be available. By default, tcg is used. If there is
-more than one accelerator specified, the next one is used if the previous one
-fails to initialize.
+kvm, xen, hax, hvf, nvmm, whpx or tcg can be available. By default, tcg is used.
+If there is more than one accelerator specified, the next one is used if the
+previous one fails to initialize.
 @table @option
 @item thread=single|multi
 Controls number of TCG threads. When the TCG is multi-threaded there will be one
