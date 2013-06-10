$NetBSD: patch-src_gallium_include_pipe_p__config.h,v 1.2 2013/06/10 12:29:54 mef Exp $

Adjust Endianness for PowerPC or SunOS.

--- Mesa-7.11.2/src/gallium/include/pipe/p_config.h.orig	2011-10-15 09:43:58.000000000 +0900
+++ src/gallium/include/pipe/p_config.h	2013-06-10 15:35:08.000000000 +0900
@@ -99,7 +99,7 @@
 #endif
 #endif
 
-#if defined(__ppc__) || defined(__ppc64__) || defined(__PPC__)
+#if defined(__ppc__) || defined(__ppc64__) || defined(__PPC__) || defined(__powerpc__)
 #define PIPE_ARCH_PPC
 #if defined(__ppc64__) || defined(__PPC64__)
 #define PIPE_ARCH_PPC_64
@@ -129,6 +129,15 @@
 # define PIPE_ARCH_BIG_ENDIAN
 #endif
 
+#elif defined(__sun)
+#include <sys/isa_defs.h>
+
+#if defined(_LITTLE_ENDIAN)
+# define PIPE_ARCH_LITTLE_ENDIAN
+#elif defined(_BIG_ENDIAN)
+# define PIPE_ARCH_BIG_ENDIAN
+#endif
+
 #else
 
 #if defined(PIPE_ARCH_X86) || defined(PIPE_ARCH_X86_64)
