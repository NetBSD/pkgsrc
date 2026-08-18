$NetBSD: patch-Misc_common.h,v 1.4 2026/08/18 10:07:28 adam Exp $

On Darwin, don't redefine swab().
Add NetBSD support and check for _LITTLE_ENDIAN

--- Misc/common.h.orig	2019-12-17 16:05:14.000000000 +0000
+++ Misc/common.h
@@ -66,15 +66,15 @@
 #endif
 
 /* For beboxes and Mac use a hand-made version of swab */
-#if defined(TARGET_OS_VMS) || defined(TARGET_OS_BEOS) || defined(TARGET_OS_MAC) || defined(__STRICT_ANSI__)
+#if defined(TARGET_OS_VMS) || defined(TARGET_OS_BEOS) || defined(__STRICT_ANSI__)
 void swab( const char *from, char *to, int nbytes);
 #endif
 
-#if defined(__GLIBC__)
+#if defined(__GLIBC__) || defined(__NetBSD__)
 #include <endian.h>
 #undef BIG_ENDIAN
 #undef LITTLE_ENDIAN
-#if __BYTE_ORDER == __LITTLE_ENDIAN
+#if __BYTE_ORDER == __LITTLE_ENDIAN || _BYTE_ORDER == _LITTLE_ENDIAN
 #  define LITTLE_ENDIAN
 #else
 #  define BIG_ENDIAN
@@ -82,7 +82,7 @@ void swab( const char *from, char *to, i
 #else
 
 /* Intel based machine ? */
-#if defined(__i386) || defined(_M_X86) || defined(TARGET_OS_VMS)
+#if defined(__i386) || defined(_M_X86) || defined(TARGET_OS_VMS) || defined(__x86_64__) || defined(__arm64__)
 #undef BIG_ENDIAN
 #undef LITTLE_ENDIAN
 # define LITTLE_ENDIAN
