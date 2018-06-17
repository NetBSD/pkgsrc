$NetBSD: patch-gcc_config_alpha_linux.h,v 1.1 2018/06/17 19:50:52 maya Exp $

Move linux-specific definitions to linux file.
PR target/85095, https://gcc.gnu.org/ml/gcc-patches/2018-05/msg01370.html

--- gcc/config/alpha/linux.h.orig	2017-01-01 12:07:43.905435000 +0000
+++ gcc/config/alpha/linux.h
@@ -78,6 +78,32 @@ along with GCC; see the file COPYING3.  
 
 #define TARGET_POSIX_IO
 
+/* Provide a STARTFILE_SPEC appropriate for ELF.  Here we add the
+   (even more) magical crtbegin.o file which provides part of the
+   support for getting C++ file-scope static object constructed
+   before entering `main'.  */
+
+#undef	STARTFILE_SPEC
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
+#undef	ENDFILE_SPEC
+#define ENDFILE_SPEC \
+  "%{Ofast|ffast-math|funsafe-math-optimizations:crtfastmath.o%s} \
+   %{shared|pie:crtendS.o%s;:crtend.o%s} crtn.o%s"
+
 #define LINK_GCC_C_SEQUENCE_SPEC \
   "%{static:--start-group} %G %L %{static:--end-group}%{!static:%G}"
 
