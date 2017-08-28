$NetBSD: patch-gcc_config_alpha_linux.h,v 1.2 2017/08/28 18:26:38 maya Exp $

Move Linux-specific spec definitions to the Linux file.

--- gcc/config/alpha/linux.h.orig	2015-01-05 12:33:28.000000000 +0000
+++ gcc/config/alpha/linux.h
@@ -74,6 +74,32 @@ along with GCC; see the file COPYING3.  
 
 #define TARGET_POSIX_IO
 
+/* Provide a STARTFILE_SPEC appropriate for ELF.  Here we add the
+   (even more) magical crtbegin.o file which provides part of the
+   support for getting C++ file-scope static object constructed
+   before entering `main'.  */
+ 
+#undef  STARTFILE_SPEC
+#ifdef HAVE_LD_PIE
+#define STARTFILE_SPEC \
+  "%{!shared: %{pg|p:gcrt1.o%s;pie:Scrt1.o%s;:crt1.o%s}}\
+   crti.o%s %{static:crtbeginT.o%s;shared|pie:crtbeginS.o%s;:crtbegin.o%s}"
+#else
+#define STARTFILE_SPEC \
+  "%{!shared: %{pg|p:gcrt1.o%s;:crt1.o%s}}\
+   crti.o%s %{static:crtbeginT.o%s;shared|pie:crtbeginS.o%s;:crtbegin.o%s}"
+#endif
+ 
+/* Provide a ENDFILE_SPEC appropriate for ELF.  Here we tack on the
+   magical crtend.o file which provides part of the support for
+   getting C++ file-scope static object constructed before entering
+   `main', followed by a normal ELF "finalizer" file, `crtn.o'.  */
+ 
+#undef  ENDFILE_SPEC
+#define ENDFILE_SPEC \
+  "%{Ofast|ffast-math|funsafe-math-optimizations:crtfastmath.o%s} \
+   %{shared|pie:crtendS.o%s;:crtend.o%s} crtn.o%s"
+
 #define LINK_GCC_C_SEQUENCE_SPEC \
   "%{static:--start-group} %G %L %{static:--end-group}%{!static:%G}"
 
