$NetBSD: patch-ld_emulparams_armelfb__nbsd__eabihf.sh,v 1.1 2022/01/24 15:10:46 fcambus Exp $

NetBSD/aarch64 support patches for ld from src.

--- ld/emulparams/armelfb_nbsd_eabihf.sh.orig	2022-01-24 10:55:35.489852209 +0000
+++ ld/emulparams/armelfb_nbsd_eabihf.sh
@@ -0,0 +1,2 @@
+. ${srcdir}/emulparams/armelf_nbsd_eabihf.sh
+OUTPUT_FORMAT="elf32-bigarm"
