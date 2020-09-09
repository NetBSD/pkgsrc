$NetBSD: patch-SP_code_qcommon_q__platform.h,v 1.2 2020/09/09 11:22:27 nia Exp $

Remove hardcoded list of architectures.

--- SP/code/qcommon/q_platform.h.orig	2019-03-16 18:09:48.000000000 +0000
+++ SP/code/qcommon/q_platform.h
@@ -201,7 +201,7 @@ Foundation, Inc., 51 Franklin St, Fifth 
 
 //=================================================================== BSD ===
 
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 
 #include <sys/types.h>
 #include <machine/endian.h>
@@ -216,19 +216,20 @@ Foundation, Inc., 51 Franklin St, Fifth 
 #define OS_STRING "openbsd"
 #elif defined(__NetBSD__)
 #define OS_STRING "netbsd"
+#elif defined(__DragonFly__)
+#define OS_STRING "dragonfly"
 #endif
 
 #define ID_INLINE inline
 #define PATH_SEP '/'
 
-#ifdef __i386__
-#define ARCH_STRING "i386"
-#elif defined __amd64__
+#if !defined(ARCH_STRING)
+# error ARCH_STRING should be defined by the Makefile
+#endif
+
+#if defined __x86_64__
 #undef idx64
 #define idx64 1
-#define ARCH_STRING "amd64"
-#elif defined __axp__
-#define ARCH_STRING "alpha"
 #endif
 
 #if BYTE_ORDER == BIG_ENDIAN
