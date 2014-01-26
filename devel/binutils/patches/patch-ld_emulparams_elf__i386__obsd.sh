$NetBSD: patch-ld_emulparams_elf__i386__obsd.sh,v 1.1 2014/01/26 03:49:01 ryoon Exp $

--- ld/emulparams/elf_i386_obsd.sh.orig	2014-01-26 00:08:31.000000000 +0000
+++ ld/emulparams/elf_i386_obsd.sh
@@ -0,0 +1,24 @@
+. ${srcdir}/emulparams/elf_i386.sh
+. ${srcdir}/emulparams/elf_obsd.sh
+
+if test "${LD_FLAG#"${LD_FLAG%pie}"}" = "pie"; then
+  TEXT_START_ADDR=0x0
+  if test "${LD_FLAG%%(cpie|pie)}" = "Z"; then
+    RODATA_PADSIZE=${MAXPAGESIZE}
+  else
+    RODATA_PADSIZE=0x20000000
+  fi
+else
+  if test "${LD_FLAG%%(cpie|pie)}" = "Z"; then
+    TEXT_START_ADDR=0x08048000
+    RODATA_PADSIZE=${MAXPAGESIZE}
+  else
+    TEXT_START_ADDR=0x1C000000
+    RODATA_PADSIZE=0x20000000
+  fi
+fi
+
+RODATA_ALIGN=". = ALIGN(${RODATA_PADSIZE})"
+RODATA_ALIGN_ADD="${TEXT_START_ADDR}"
+
+unset PAD_PLT
