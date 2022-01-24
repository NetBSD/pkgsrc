$NetBSD: patch-ld_emulparams_aarch64nbsdb.sh,v 1.1 2022/01/24 15:10:46 fcambus Exp $

NetBSD/aarch64 support patches for ld from src.

--- ld/emulparams/aarch64nbsdb.sh.orig	2022-01-24 10:48:14.877303134 +0000
+++ ld/emulparams/aarch64nbsdb.sh
@@ -0,0 +1,2 @@
+. ${srcdir}/emulparams/aarch64nbsd.sh
+OUTPUT_FORMAT="elf64-bigaarch64"
