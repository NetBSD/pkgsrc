$NetBSD: patch-code_qcommon_q__platform.h,v 1.1 2021/05/21 15:01:52 nia Exp $

Remove hardcoded list of BSD archs - implement multi-arch generically

https://github.com/ioquake/ioq3/pull/466

--- code/qcommon/q_platform.h.orig	2019-12-07 13:16:15.000000000 +0000
+++ code/qcommon/q_platform.h
@@ -221,14 +221,13 @@ Foundation, Inc., 51 Franklin St, Fifth 
 #define ID_INLINE inline
 #define PATH_SEP '/'
 
-#ifdef __i386__
-#define ARCH_STRING "x86"
-#elif defined __amd64__
+#if !defined(ARCH_STRING)
+# error ARCH_STRING should be defined by the Makefile
+#endif
+
+#if defined __x86_64__
 #undef idx64
 #define idx64 1
-#define ARCH_STRING "x86_64"
-#elif defined __axp__
-#define ARCH_STRING "alpha"
 #endif
 
 #if BYTE_ORDER == BIG_ENDIAN
