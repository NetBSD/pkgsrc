$NetBSD: patch-code_qcommon_q__platform.h,v 1.1 2021/04/03 15:34:04 nia Exp $

Get ARCH_STRING from the build environment rather than hardcoded lists.

--- code/qcommon/q_platform.h.orig	2011-11-08 20:27:31.000000000 +0000
+++ code/qcommon/q_platform.h
@@ -134,13 +134,15 @@ Foundation, Inc., 51 Franklin St, Fifth 
 #define PATH_SEP '/'
 
 #ifdef __ppc__
-#define ARCH_STRING "ppc"
 #define Q3_BIG_ENDIAN
 #elif defined __i386__
-#define ARCH_STRING "i386"
 #define Q3_LITTLE_ENDIAN
 #endif
 
+#if !defined(ARCH_STRING)
+# error ARCH_STRING should be defined by the Makefile
+#endif
+
 #define DLL_EXT ".dylib"
 
 #endif
@@ -155,34 +157,8 @@ Foundation, Inc., 51 Franklin St, Fifth 
 #define ID_INLINE inline
 #define PATH_SEP '/'
 
-#if defined __i386__
-#define ARCH_STRING "i386"
-#elif defined __x86_64__
-#define ARCH_STRING "x86_64"
-#elif defined __powerpc64__
-#define ARCH_STRING "ppc64"
-#elif defined __powerpc__
-#define ARCH_STRING "ppc"
-#elif defined __s390__
-#define ARCH_STRING "s390"
-#elif defined __s390x__
-#define ARCH_STRING "s390x"
-#elif defined __ia64__
-#define ARCH_STRING "ia64"
-#elif defined __alpha__
-#define ARCH_STRING "alpha"
-#elif defined __sparc__
-#define ARCH_STRING "sparc"
-#elif defined __arm__
-#define ARCH_STRING "arm"
-#elif defined __cris__
-#define ARCH_STRING "cris"
-#elif defined __hppa__
-#define ARCH_STRING "hppa"
-#elif defined __mips__
-#define ARCH_STRING "mips"
-#elif defined __sh__
-#define ARCH_STRING "sh"
+#if !defined(ARCH_STRING)
+# error ARCH_STRING should be defined by the Makefile
 #endif
 
 #if __FLOAT_WORD_ORDER == __BIG_ENDIAN
@@ -217,10 +193,8 @@ Foundation, Inc., 51 Franklin St, Fifth 
 #define ID_INLINE inline
 #define PATH_SEP '/'
 
-#ifdef __i386__
-#define ARCH_STRING "i386"
-#elif defined __axp__
-#define ARCH_STRING "alpha"
+#if !defined(ARCH_STRING)
+# error ARCH_STRING should be defined by the Makefile
 #endif
 
 #if BYTE_ORDER == BIG_ENDIAN
@@ -244,10 +218,8 @@ Foundation, Inc., 51 Franklin St, Fifth 
 #define ID_INLINE inline
 #define PATH_SEP '/'
 
-#ifdef __i386__
-#define ARCH_STRING "i386"
-#elif defined __sparc
-#define ARCH_STRING "sparc"
+#if !defined(ARCH_STRING)
+# error ARCH_STRING should be defined by the Makefile
 #endif
 
 #if defined( _BIG_ENDIAN )
