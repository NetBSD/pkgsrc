$NetBSD: patch-gcc_unwind-dw2-fde-openbsd.c,v 1.1 2014/01/25 13:38:48 ryoon Exp $

--- gcc/unwind-dw2-fde-openbsd.c.orig	2014-01-25 06:53:23.000000000 +0000
+++ gcc/unwind-dw2-fde-openbsd.c
@@ -0,0 +1,10 @@
+/* XXX This file provides a few defines such that we can compile the
+   source from unwind-dw2-fde-glibc.c on OpenBSD.  Hopefully we can
+   integrate these defines in that file and rename it to something
+   like unwind-de2-fde-phdr.c in the up-stream sources.  */
+
+#define ElfW(type) Elf_##type
+
+#define __GLIBC__ 3           /* Fool unwind-dw2-fde-glibc.c.  */
+#include "unwind-dw2-fde-glibc.c"
+
