$NetBSD: patch-MACS3_fermi-lite_ksw.c,v 1.2 2024/02/28 13:38:48 bacon Exp $

# Use SIMDE sse2.h

--- MACS3/fermi-lite/ksw.c.orig	2023-12-21 22:20:16.716124047 +0000
+++ MACS3/fermi-lite/ksw.c
@@ -28,7 +28,7 @@
 
 /* I modified this according to https://github.com/lh3/bwa/pull/283/*/
 #ifdef USE_SIMDE
-#include "lib/x86/sse2.h"
+#include <simde/x86/sse2.h>
 #else
 #include <emmintrin.h>
 #endif
