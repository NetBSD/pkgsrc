$NetBSD: patch-lib_elf__py.c,v 1.3 2026/09/20 18:06:12 wiz Exp $

Avoid conflict between symbols in elf.h and libelf.h.

--- lib/elf_py.c.orig	2026-09-20 18:03:27.605799319 +0000
+++ lib/elf_py.c
@@ -57,7 +57,6 @@
 #endif
 
 #include <elf.h>
-#include <libelf.h>
 #include <gelf.h>
 
 #include "typesafe.h"
