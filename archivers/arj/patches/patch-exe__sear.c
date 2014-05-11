$NetBSD: patch-exe__sear.c,v 1.1 2014/05/11 20:56:16 rodent Exp $

Include elf_abi.h instead of elf.h for OpenBSD.

--- exe_sear.c.orig	2003-10-16 10:32:46.000000000 +0000
+++ exe_sear.c
@@ -10,6 +10,8 @@
 #ifdef ELF_EXECUTABLES
  #ifdef __QNXNTO__
     #include <libelf.h>
+ #elif defined(__OpenBSD__)
+    #include <elf_abi.h>
  #else
     #include <elf.h>
  #endif /* __QNXNTO__ */
