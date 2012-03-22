$NetBSD: patch-libpolyml_elfexport.cpp,v 1.1 2012/03/22 20:48:45 asau Exp $

--- libpolyml/elfexport.cpp.orig	2010-04-14 22:13:42.000000000 +0000
+++ libpolyml/elfexport.cpp
@@ -62,6 +62,13 @@
 #ifdef HAVE_SYS_ELF_386_H
 #include <sys/elf_386.h>
 #endif
+#if defined(__NetBSD__) && defined(HOSTARCHITECTURE_X86_64)
+#include <i386/elf_machdep.h>
+#endif
+#if defined(__DragonFly__) && (defined(HOSTARCHITECTURE_X86) || defined(HOSTARCHITECTURE_X86_64))
+/* Missing definition taken from NetBSD: */
+#define	R_386_PC32	2
+#endif
 #ifdef HAVE_STRING_H
 #include <string.h>
 #endif
