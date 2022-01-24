$NetBSD: patch-ld_emulparams_armelf__nbsd__eabihf.sh,v 1.1 2022/01/24 15:10:46 fcambus Exp $

NetBSD/aarch64 support patches for ld from src.

--- ld/emulparams/armelf_nbsd_eabihf.sh.orig	2022-01-24 10:52:51.236067688 +0000
+++ ld/emulparams/armelf_nbsd_eabihf.sh
@@ -0,0 +1,20 @@
+. ${srcdir}/emulparams/armelf_nbsd.sh
+
+# Use the ARM ABI-compliant exception-handling sections.
+OTHER_READONLY_SECTIONS="
+  .ARM.extab ${RELOCATING-0} : { *(.ARM.extab${RELOCATING+* .gnu.linkonce.armextab.*}) }
+  ${RELOCATING+ PROVIDE_HIDDEN (__exidx_start = .); }
+  .ARM.exidx ${RELOCATING-0} : { *(.ARM.exidx${RELOCATING+* .gnu.linkonce.armexidx.*}) }
+  ${RELOCATING+ PROVIDE_HIDDEN (__exidx_end = .); }"
+
+case "$target" in
+  arm*-*-netbsdelf*-*eabihf*)
+    ;;
+  aarch64*-*-netbsd* | arm*-*-netbsdelf*)
+    case "$EMULATION_NAME" in
+    *armelf*eabihf)
+      LIB_PATH='=/usr/lib/eabihf'
+      ;;
+    esac
+    ;;
+esac
