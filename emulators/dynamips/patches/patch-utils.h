$NetBSD: patch-utils.h,v 1.1 2015/02/19 14:18:23 joerg Exp $

--- utils.h.orig	2015-02-10 10:34:29.000000000 +0000
+++ utils.h
@@ -54,6 +54,12 @@
 #define ARCH_BYTE_ORDER ARCH_LITTLE_ENDIAN
 #elif defined(__ia64__)
 #define ARCH_BYTE_ORDER ARCH_LITTLE_ENDIAN
+#elif defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && defined(__ORDER_BIG_ENDIAN__)
+#  if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
+#  define ARCH_BYTE_ORDER ARCH_LITTLE_ENDIAN
+#  else
+#  define ARCH_BYTE_ORDER ARCH_BIG_ENDIAN
+#  endif
 #endif
 
 #ifndef ARCH_BYTE_ORDER
@@ -80,8 +86,13 @@
 #endif
 
 /* Useful attributes for functions */
+#ifdef __arm__
+#define asmlinkage
+#define fastcall
+#else
 #define asmlinkage __attribute__((regparm(0)))
 #define fastcall   __attribute__((regparm(3)))
+#endif
 
 #if __GNUC__ > 2
 #define forced_inline inline __attribute__((always_inline))
