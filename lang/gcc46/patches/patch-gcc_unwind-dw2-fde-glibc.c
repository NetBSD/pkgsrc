$NetBSD: patch-gcc_unwind-dw2-fde-glibc.c,v 1.1 2014/01/25 13:38:48 ryoon Exp $

--- gcc/unwind-dw2-fde-glibc.c.orig	2010-12-23 12:08:21.000000000 +0000
+++ gcc/unwind-dw2-fde-glibc.c
@@ -33,7 +33,7 @@
 
 #include "tconfig.h"
 #include "tsystem.h"
-#ifndef inhibit_libc
+#if !defined(inhibit_libc) && !defined(__OpenBSD__)
 #include <elf.h>		/* Get DT_CONFIG.  */
 #endif
 #include "coretypes.h"
