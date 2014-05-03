$NetBSD: patch-src_gallium_include_pipe_p__config.h,v 1.4 2014/05/03 19:03:59 ryoon Exp $

Adjust Endianness for PowerPC, NetBSD, OpenBSD or SunOS.

--- src/gallium/include/pipe/p_config.h.orig	2011-10-15 00:43:58.000000000 +0000
+++ src/gallium/include/pipe/p_config.h
@@ -99,7 +99,7 @@
 #endif
 #endif
 
-#if defined(__ppc__) || defined(__ppc64__) || defined(__PPC__)
+#if defined(__ppc__) || defined(__ppc64__) || defined(__PPC__) || defined(__powerpc__)
 #define PIPE_ARCH_PPC
 #if defined(__ppc64__) || defined(__PPC64__)
 #define PIPE_ARCH_PPC_64
@@ -129,6 +129,28 @@
 # define PIPE_ARCH_BIG_ENDIAN
 #endif
 
+#elif defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__NetBSD__)
+#include <sys/endian.h>
+#else /* OpenBSD */
+#include <machine/endian.h>
+#endif
+
+#if _BYTE_ORDER == _LITTLE_ENDIAN
+# define PIPE_ARCH_LITTLE_ENDIAN
+#elif _BYTE_ORDER == _BIG_ENDIAN
+# define PIPE_ARCH_BIG_ENDIAN
+#endif
+
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
