$NetBSD: patch-ksw.c,v 1.1 2023/05/18 14:05:15 bacon Exp $

# Use SIMDE to support non-x86 architectures

--- ksw.c.orig	2017-10-23 17:10:17.000000000 +0000
+++ ksw.c
@@ -26,7 +26,9 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <assert.h>
-#include <emmintrin.h>
+// #include <emmintrin.h>
+#define SIMDE_ENABLE_NATIVE_ALIASES
+#include <simde/x86/sse2.h>
 #include "ksw.h"
 
 #ifdef USE_MALLOC_WRAPPERS
