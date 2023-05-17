$NetBSD: patch-sse__util.h,v 1.1 2023/05/17 21:55:34 bacon Exp $

# Support non-x86

--- sse_util.h.orig	2020-07-24 20:07:54.000000000 +0000
+++ sse_util.h
@@ -20,11 +20,14 @@
 #ifndef SSE_UTIL_H_
 #define SSE_UTIL_H_
 
+#define SIMDE_ENABLE_NATIVE_ALIASES
+#include <simde/x86/sse2.h>
+
 #include "assert_helpers.h"
 #include "ds.h"
 #include "limit.h"
 #include <iostream>
-#include <emmintrin.h>
+// #include <emmintrin.h>		// Replace with simde when possible
 
 class EList_m128i {
 public:
