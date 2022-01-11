$NetBSD: patch-porting.h,v 1.1 2022/01/11 15:21:04 fcambus Exp $

Don't include alloca.h on NetBSD.

--- porting.h.orig	2021-07-22 21:23:46.000000000 +0000
+++ porting.h
@@ -41,7 +41,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include "elf.h"
-#if !defined(__FreeBSD__) && !defined(__OpenBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
 # include <alloca.h>
 #endif
 #if defined(__linux__)
