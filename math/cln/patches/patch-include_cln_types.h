$NetBSD: patch-include_cln_types.h,v 1.1 2015/02/07 19:53:41 jdc Exp $

--- include/cln/types.h.orig	2015-02-07 18:09:17.000000000 +0000
+++ include/cln/types.h	2015-02-07 18:43:34.000000000 +0000
@@ -48,7 +48,7 @@
     #undef HAVE_LONGLONG
    #endif
   #endif
-  #if defined(HAVE_LONGLONG) && (defined(__alpha__) || defined(__ia64__) || defined(__mips64__) || defined(__powerpc64__) || defined(__x86_64__))
+  #if defined(HAVE_LONGLONG) && (defined(__alpha__) || defined(__ia64__) || defined(__mips64__) || defined(__powerpc64__) || defined(__x86_64__) || defined(__sparc64__))
     // 64 bit registers in hardware
     #define HAVE_FAST_LONGLONG
   #endif
@@ -76,7 +76,7 @@
 
 // Integer type used for counters.
 // Constraint: sizeof(uintC) >= sizeof(uintL)
-  #if (defined(HAVE_FAST_LONGLONG) && (defined(__alpha__) || defined(__ia64__) || defined(__powerpc64__) || defined(__x86_64__)))
+  #if (defined(HAVE_FAST_LONGLONG) && (defined(__alpha__) || defined(__ia64__) || defined(__powerpc64__) || defined(__x86_64__) || defined(__sparc64__)))
     #define intCsize long_bitsize
     typedef long           sintC;
     typedef unsigned long  uintC;
@@ -88,7 +88,7 @@
 
 // Integer type used for lfloat exponents.
 // Constraint: sizeof(uintE) >= sizeof(uintC)
-#if (defined(HAVE_LONGLONG) && (defined(__alpha__) || defined(__ia64__) || defined(__powerpc64__) || defined(__x86_64__) || defined(__i386__) || defined(__mips__) || defined(__rs6000__)))
+#if (defined(HAVE_LONGLONG) && (defined(__alpha__) || defined(__ia64__) || defined(__powerpc64__) || defined(__x86_64__) || defined(__i386__) || defined(__mips__) || defined(__rs6000__) || defined(__sparc64__)))
     #define intEsize 64
     typedef sint64  sintE;
     typedef uint64  uintE;
@@ -127,7 +127,7 @@
     typedef int sintD;
     typedef unsigned int uintD;
   #else  // we are not using GMP, so just guess something reasonable
-    #if (defined(HAVE_FAST_LONGLONG) && (defined(__alpha__) || defined(__ia64__) || defined(__powerpc64__) || defined(__x86_64__) || defined(__sparc64)))
+    #if (defined(HAVE_FAST_LONGLONG) && (defined(__alpha__) || defined(__ia64__) || defined(__powerpc64__) || defined(__x86_64__) || defined(__sparc64__)))
       #define intDsize 64
       typedef sint64  sintD;
       typedef uint64  uintD;
