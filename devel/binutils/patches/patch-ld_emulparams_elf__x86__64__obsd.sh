$NetBSD: patch-ld_emulparams_elf__x86__64__obsd.sh,v 1.1 2014/01/26 03:49:01 ryoon Exp $

--- ld/emulparams/elf_x86_64_obsd.sh.orig	2014-01-26 00:08:31.000000000 +0000
+++ ld/emulparams/elf_x86_64_obsd.sh
@@ -0,0 +1,2 @@
+. ${srcdir}/emulparams/elf_x86_64.sh
+. ${srcdir}/emulparams/elf_obsd.sh
