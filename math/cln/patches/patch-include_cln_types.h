$NetBSD: patch-include_cln_types.h,v 1.2 2015/02/07 20:18:06 jdc Exp $

--- include/cln/types.h.orig	2009-06-14 20:49:32.000000000 +0100
+++ include/cln/types.h	2015-02-07 20:03:43.000000000 +0000
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
-    #if (defined(HAVE_FAST_LONGLONG) && (defined(__alpha__) || defined(__ia64__) || defined(__powerpc64__) || defined(__x86_64__)))
+    #if (defined(HAVE_FAST_LONGLONG) && (defined(__alpha__) || defined(__ia64__) || defined(__powerpc64__) || defined(__x86_64__) || defined(__sparc64__)))
       #define intDsize 64
       typedef sint64  sintD;
       typedef uint64  uintD;
