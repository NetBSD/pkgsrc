$NetBSD: patch-utility_src_parasail_internal__sse.h,v 1.2 2023/05/20 11:27:27 bacon Exp $

# Portability

--- utility/src/parasail/internal_sse.h.orig	2021-12-17 22:10:09 UTC
+++ utility/src/parasail/internal_sse.h
@@ -10,7 +10,8 @@
 
 #include <stdint.h>
 
-#include <emmintrin.h>
+#define SIMDE_ENABLE_NATIVE_ALIASES
+#include <simde.h>
 
 #include "parasail.h"
 
