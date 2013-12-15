$NetBSD: patch-libpolyml_elfexport.cpp,v 1.2 2013/12/15 18:35:23 asau Exp $

--- libpolyml/elfexport.cpp.orig	2013-06-11 11:13:52.000000000 +0000
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
 #ifdef HAVE_STRING_H
 #include <string.h>
 #endif
