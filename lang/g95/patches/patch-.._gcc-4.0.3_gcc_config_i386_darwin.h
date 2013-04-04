$NetBSD: patch-.._gcc-4.0.3_gcc_config_i386_darwin.h,v 1.1 2013/04/04 14:31:32 jperkin Exp $

Fix -arch type on OSX.

--- ../gcc-4.0.3/gcc/config/i386/darwin.h.orig	2013-04-04 14:07:01.000000000 +0000
+++ ../gcc-4.0.3/gcc/config/i386/darwin.h	2013-04-04 14:07:38.000000000 +0000
@@ -23,7 +23,7 @@
 #undef TARGET_MACHO
 #define TARGET_MACHO 1
 
-#define TARGET_VERSION fprintf (stderr, " (i686 Darwin)");
+#define TARGET_VERSION fprintf (stderr, " (i386 Darwin)");
 
 #define TARGET_OS_CPP_BUILTINS()                \
   do                                            \
@@ -43,12 +43,12 @@
   %{g: %{!fno-eliminate-unused-debug-symbols: -feliminate-unused-debug-symbols }}"
 
 #undef ASM_SPEC
-#define ASM_SPEC "-arch i686 -force_cpusubtype_ALL"
+#define ASM_SPEC "-arch i386 -force_cpusubtype_ALL"
 
 #undef SUBTARGET_EXTRA_SPECS
 #define SUBTARGET_EXTRA_SPECS					\
-  { "darwin_arch", "i686" },					\
-  { "darwin_subarch", "%{march=pentium3:pentIIm3;:i686}" },
+  { "darwin_arch", "i386" },					\
+  { "darwin_subarch", "%{march=pentium3:pentIIm3;:i386}" },
    
 
 /* Use the following macro for any Darwin/x86-specific command-line option
