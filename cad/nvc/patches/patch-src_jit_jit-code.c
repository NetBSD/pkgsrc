$NetBSD: patch-src_jit_jit-code.c,v 1.1 2025/12/31 21:40:35 ryoon Exp $

* Load some ELF definitions under older and new NetBSDs.

--- src/jit/jit-code.c.orig	2025-11-19 20:36:15.000000000 +0000
+++ src/jit/jit-code.c
@@ -42,8 +42,15 @@
 #include <mach-o/arm64/reloc.h>
 #include <mach-o/x86_64/reloc.h>
 #else
+#if defined(__NetBSD__)
+#include <sys/elfdefinitions.h>
+#if _USE_SYS_ELFDEFINITIONS_H_ + 0 > 0
 #include <elf.h>
 #endif
+#else
+#include <elf.h>
+#endif
+#endif
 
 #ifdef HAVE_CAPSTONE
 #include <capstone.h>
