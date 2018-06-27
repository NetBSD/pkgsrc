$NetBSD: patch-i18n_double-conversion-utils.h,v 1.1 2018/06/27 19:06:17 maya Exp $

Big endian is a thing and typically has the same behaviour with regards to float
sizes.

--- i18n/double-conversion-utils.h.orig	2018-03-26 13:38:30.000000000 +0000
+++ i18n/double-conversion-utils.h
@@ -77,7 +77,7 @@ inline void abort_noreturn() { abort(); 
 // On Linux,x86 89255e-22 != Div_double(89255.0/1e22)
 // ICU PATCH: Enable ARM builds for Windows with 'defined(_M_ARM)'.
 #if defined(_M_X64) || defined(__x86_64__) || \
-    defined(__ARMEL__) || defined(__avr32__) || defined(_M_ARM) || \
+    defined(__ARMEL__) || defined(__ARMEB__) || defined(__avr32__) || defined(_M_ARM) || \
     defined(__hppa__) || defined(__ia64__) || \
     defined(__mips__) || \
     defined(__powerpc__) || defined(__ppc__) || defined(__ppc64__) || \
