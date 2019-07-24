$NetBSD: patch-i18n_double-conversion-utils.h,v 1.5 2019/07/24 17:02:07 rin Exp $

Add support for ARMEB.

--- i18n/double-conversion-utils.h.orig	2019-07-24 21:04:19.876508903 +0900
+++ i18n/double-conversion-utils.h	2019-07-24 21:05:44.988164937 +0900
@@ -92,7 +92,7 @@ int main(int argc, char** argv) {
 //
 // If it prints "correct" then the architecture should be here, in the "correct" section.
 #if defined(_M_X64) || defined(__x86_64__) || \
-    defined(__ARMEL__) || defined(__avr32__) || defined(_M_ARM) || defined(_M_ARM64) || \
+    defined(__ARMEL__) || defined(__ARMEB__) || defined(__avr32__) || defined(_M_ARM) || defined(_M_ARM64) || \
     defined(__hppa__) || defined(__ia64__) || \
     defined(__mips__) || \
     defined(__powerpc__) || defined(__ppc__) || defined(__ppc64__) || \
