$NetBSD: patch-src_runtime_include_asm-base.h,v 1.1 2024/04/22 18:35:06 he Exp $

Add support for NetBSD/powerpc.

--- src/runtime/include/asm-base.h.orig	2022-07-28 04:55:45.000000000 +0000
+++ src/runtime/include/asm-base.h
@@ -81,7 +81,7 @@
 #    define LABEL(ID)	ID:
 #    define __SC__      @
 
-#  elif defined(OPSYS_OPENBSD)
+#  elif defined(OPSYS_OPENBSD) || defined(OPSYS_NETBSD)
 #    define CFUNSYM(ID) CSYM(ID)
 #    define GLOBAL(ID)  .globl  ID
 #    define TEXT        .text
