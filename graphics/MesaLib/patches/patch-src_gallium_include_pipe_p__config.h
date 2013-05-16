$NetBSD: patch-src_gallium_include_pipe_p__config.h,v 1.1 2013/05/16 05:22:02 richard Exp $

--- src/gallium/include/pipe/p_config.h.orig	2011-10-15 00:43:58.000000000 +0000
+++ src/gallium/include/pipe/p_config.h
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
