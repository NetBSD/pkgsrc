$NetBSD: patch-libpolyml_elfexport.cpp,v 1.4 2015/12/29 23:34:54 dholland Exp $

Fix build on NetBSD.
Fix build on Dragonfly.

--- libpolyml/elfexport.cpp.orig	2013-10-15 16:25:39.000000000 +0000
+++ libpolyml/elfexport.cpp
@@ -65,6 +65,13 @@
 #ifdef HAVE_SYS_ELF_AMD64_H
 #include <sys/elf_amd64.h>
 #endif
+#if defined(__NetBSD__) && defined(HOSTARCHITECTURE_X86_64)
+#include <i386/elf_machdep.h>
+#endif
+#if defined(__DragonFly__) && (defined(HOSTARCHITECTURE_X86) || defined(HOSTARCHITECTURE_X86_64))
+/* Missing definition taken from NetBSD: */
+#define	R_386_PC32	2
+#endif
 
 // Android has the ARM relocation symbol here
 #ifdef HAVE_ASM_ELF_H
