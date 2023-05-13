$NetBSD: patch-dcraw.cc,v 1.3 2023/05/13 11:55:55 gdt Exp $

The first hunk works around the combination of:
  - NetBSD stdint.h/int_limit.sh not defining UINT_LEAST64_MAX in c++
     mode before C++11
  - ufraw including C headers in C++ mode
  - ufraw being C++03
by just asking for the limit macros to be defined.

\todo Explain second hunk.  This seems to be about avoiding a SWAP macro
and is likely not very interesting.

--- dcraw.cc.orig	2015-06-16 03:58:38.000000000 +0000
+++ dcraw.cc
@@ -24,6 +24,9 @@ extern "C" {
 
 #define DCRAW_VERSION "9.26"
 
+/* Obtain UINT32_LEAST_MAX even in C++ mode. */
+#define __STDC_LIMIT_MACROS
+
 #ifndef _GNU_SOURCE
 #define _GNU_SOURCE
 #endif
@@ -9240,11 +9243,15 @@ canon_a5:
       filters = 0x16161616;
     }
     if (make[0] == 'O') {
-      i = find_green (12, 32, 1188864, 3576832);
-      c = find_green (12, 32, 2383920, 2387016);
-      if (abs(i) < abs(c)) {
-	SWAP(i,c);
+      float i_ = find_green (12, 32, 1188864, 3576832);
+      float c_ = find_green (12, 32, 2383920, 2387016);
+      if (abs(i_) < abs(c_)) {
+	c = i_;
+	i = c_;
 	load_flags = 24;
+      } else {
+	i = i_;
+	c = c_;
       }
       if ((int) i < 0) filters = 0x61616161;
     }
