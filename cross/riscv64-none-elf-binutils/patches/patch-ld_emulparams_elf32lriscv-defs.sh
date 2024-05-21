$NetBSD: patch-ld_emulparams_elf32lriscv-defs.sh,v 1.1 2024/05/21 07:08:03 skrll Exp $

--- ld/emulparams/elf32lriscv-defs.sh.orig	2024-05-19 11:23:29.496953993 +0000
+++ ld/emulparams/elf32lriscv-defs.sh
@@ -16,15 +16,8 @@ if test `echo "$host" | sed -e s/64//` =
   esac
 fi
 
-# Enable shared library support for everything except an embedded elf target.
-case "$target" in
-  riscv*-elf)
-    ;;
-  *)
-    GENERATE_SHLIB_SCRIPT=yes
-    GENERATE_PIE_SCRIPT=yes
-    ;;
-esac
+GENERATE_SHLIB_SCRIPT=yes
+GENERATE_PIE_SCRIPT=yes
 
 IREL_IN_PLT=
 TEXT_START_ADDR=0x10000
