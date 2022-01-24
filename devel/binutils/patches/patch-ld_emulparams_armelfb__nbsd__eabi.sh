$NetBSD: patch-ld_emulparams_armelfb__nbsd__eabi.sh,v 1.1 2022/01/24 15:10:46 fcambus Exp $

NetBSD/aarch64 support patches for ld from src.

--- ld/emulparams/armelfb_nbsd_eabi.sh.orig	2022-01-24 10:55:29.085452037 +0000
+++ ld/emulparams/armelfb_nbsd_eabi.sh
@@ -0,0 +1,2 @@
+. ${srcdir}/emulparams/armelf_nbsd_eabi.sh
+OUTPUT_FORMAT="elf32-bigarm"
