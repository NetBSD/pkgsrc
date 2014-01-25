$NetBSD: patch-gcc_config_i386_openbsdelf.h,v 1.1 2014/01/25 13:38:48 ryoon Exp $

--- gcc/config/i386/openbsdelf.h.orig	2010-12-22 12:06:01.000000000 +0000
+++ gcc/config/i386/openbsdelf.h
@@ -113,9 +113,6 @@ along with GCC; see the file COPYING3.  
 
 /* Assembler format: exception region output.  */
 
-/* our configuration still doesn't handle dwarf2 correctly */
-#define DWARF2_UNWIND_INFO 0
-
 /* Assembler format: alignment output.  */
 
 /* Note that we pick up ASM_OUTPUT_MAX_SKIP_ALIGN from i386/gas.h */
@@ -128,7 +125,10 @@ along with GCC; see the file COPYING3.  
    %{shared:-shared} %{R*} \
    %{static:-Bstatic} \
    %{!static:-Bdynamic} \
+   %{rdynamic:-export-dynamic} \
    %{assert*} \
    -dynamic-linker /usr/libexec/ld.so"
 
 #define OBSD_HAS_CORRECT_SPECS
+
+#define SUBTARGET32_DEFAULT_CPU "i486"
