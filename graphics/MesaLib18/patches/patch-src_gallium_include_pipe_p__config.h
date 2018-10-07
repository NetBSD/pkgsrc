$NetBSD: patch-src_gallium_include_pipe_p__config.h,v 1.1 2018/10/07 23:49:31 ryoon Exp $

* Patches for Sparc from FreeBSD ports for mesa-dri 17.2.3.

* Definitions for DragonFly already in upstream source.

--- src/gallium/include/pipe/p_config.h.orig	2017-10-19 12:23:53.000000000 +0000
+++ src/gallium/include/pipe/p_config.h
@@ -77,6 +77,12 @@
 #define PIPE_CC_ICL
 #endif
 
+#if defined(__sparc__) || defined(__sparc64__)
+#define PIPE_ARCH_SPARC
+#if defined(__sparc64__)
+#define PIPE_ARCH_SPARC_64
+#endif
+#endif
 
 /*
  * Processor architecture
@@ -131,7 +137,8 @@
 
 #if defined(PIPE_ARCH_X86) || defined(PIPE_ARCH_X86_64) || defined(PIPE_ARCH_ARM) || defined(PIPE_ARCH_AARCH64)
 #define PIPE_ARCH_LITTLE_ENDIAN
-#elif defined(PIPE_ARCH_PPC) || defined(PIPE_ARCH_PPC_64) || defined(PIPE_ARCH_S390)
+#elif defined(PIPE_ARCH_PPC) || defined(PIPE_ARCH_PPC_64) || defined(PIPE_ARCH_S390) || defined(PIPE_ARCH_SPARC) || defined(PIPE_ARCH_SPARC_64)
+
 #define PIPE_ARCH_BIG_ENDIAN
 #endif
 
