$NetBSD: patch-Source_cmELF.cxx,v 1.7 2017/04/26 18:19:31 maya Exp $

cmELF: Provide DT_RUNPATH definition fallback (netbsd-6)
https://gitlab.kitware.com/cmake/cmake/merge_requests/764

--- Source/cmELF.cxx.orig	2017-04-10 15:23:07.000000000 +0000
+++ Source/cmELF.cxx
@@ -44,6 +44,9 @@ typedef struct Elf32_Rela Elf32_Rela;
 #ifdef _SCO_DS
 #include <link.h> // For DT_SONAME etc.
 #endif
+#ifndef DT_RUNPATH
+#define DT_RUNPATH 29
+#endif
 
 // Low-level byte swapping implementation.
 template <size_t s>
