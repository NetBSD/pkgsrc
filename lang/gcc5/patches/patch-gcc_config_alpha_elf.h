$NetBSD: patch-gcc_config_alpha_elf.h,v 1.2 2017/08/28 18:26:38 maya Exp $

Move Linux-specific spec definitions to the linux file.

--- gcc/config/alpha/elf.h.orig	2015-01-05 12:33:28.000000000 +0000
+++ gcc/config/alpha/elf.h
@@ -100,32 +100,6 @@ do {									\
     ASM_OUTPUT_DEF (FILE, alias, name);				\
   } while (0)
 
-/* Provide a STARTFILE_SPEC appropriate for ELF.  Here we add the
-   (even more) magical crtbegin.o file which provides part of the
-   support for getting C++ file-scope static object constructed
-   before entering `main'.  */
-
-#undef	STARTFILE_SPEC
-#ifdef HAVE_LD_PIE
-#define STARTFILE_SPEC \
-  "%{!shared: %{pg|p:gcrt1.o%s;pie:Scrt1.o%s;:crt1.o%s}}\
-   crti.o%s %{static:crtbeginT.o%s;shared|pie:crtbeginS.o%s;:crtbegin.o%s}"
-#else
-#define STARTFILE_SPEC \
-  "%{!shared: %{pg|p:gcrt1.o%s;:crt1.o%s}}\
-   crti.o%s %{static:crtbeginT.o%s;shared|pie:crtbeginS.o%s;:crtbegin.o%s}"
-#endif
-
-/* Provide a ENDFILE_SPEC appropriate for ELF.  Here we tack on the
-   magical crtend.o file which provides part of the support for
-   getting C++ file-scope static object constructed before entering
-   `main', followed by a normal ELF "finalizer" file, `crtn.o'.  */
-
-#undef	ENDFILE_SPEC
-#define ENDFILE_SPEC \
-  "%{Ofast|ffast-math|funsafe-math-optimizations:crtfastmath.o%s} \
-   %{shared|pie:crtendS.o%s;:crtend.o%s} crtn.o%s"
-
 /* This variable should be set to 'true' if the target ABI requires
    unwinding tables even when exceptions are not used.  */
 #define TARGET_UNWIND_TABLES_DEFAULT true
