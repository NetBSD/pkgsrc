$NetBSD: patch-ext_pcre_pcrelib_config.h,v 1.2 2016/10/08 09:16:09 jdolecek Exp $

--- ext/pcre/pcrelib/config.h.orig	2016-09-29 02:15:39.000000000 +0000
+++ ext/pcre/pcrelib/config.h
@@ -400,8 +400,21 @@ them both to 0; an emulation function wi
 
 /* Define to any value to enable support for Just-In-Time compiling. */
 #if HAVE_PCRE_JIT_SUPPORT
-#define SUPPORT_JIT
+#if defined(__i386__) || defined(__i386) \
+|| defined(__x86_64__) \
+|| defined(__arm__) || defined(__ARM__) \
+|| defined (__aarch64__) \
+|| defined(__ppc64__) || defined(__powerpc64__) || defined(_ARCH_PPC64) \
+|| (defined(_POWER) && defined(__64BIT__)) \
+|| defined(__ppc__) || defined(__powerpc__) || defined(_ARCH_PPC) \
+|| defined(_ARCH_PWR) || defined(_ARCH_PWR2) || defined(_POWER) \
+|| (defined(__mips__) && !defined(_LP64)) \
+|| defined(__mips64) \
+|| defined(__sparc__) || defined(__sparc) \
+|| defined(__tilegx__)
+  #define SUPPORT_JIT
 #endif
+#endif /* HAVE_PCRE_JIT_SUPPORT */
 
 /* Define to any value to allow pcregrep to be linked with libbz2, so that it
    is able to handle .bz2 files. */
