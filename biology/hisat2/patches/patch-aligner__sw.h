$NetBSD: patch-aligner__sw.h,v 1.1 2023/05/17 21:55:34 bacon Exp $

# Support non-x86

--- aligner_sw.h.orig	2020-07-24 20:07:54.000000000 +0000
+++ aligner_sw.h
@@ -66,11 +66,14 @@
 
 #define INLINE_CUPS
 
+#define	SIMDE_ENABLE_NATIVE_ALIASES
+
+#include <simde/x86/sse2.h>
 #include <stdint.h>
 #include <iostream>
 #include <limits>
 #include "threading.h"
-#include <emmintrin.h>
+// #include <emmintrin.h>	// Replace this with simde when possible
 #include "aligner_sw_common.h"
 #include "aligner_sw_nuc.h"
 #include "ds.h"
