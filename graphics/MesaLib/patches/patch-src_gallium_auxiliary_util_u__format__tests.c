$NetBSD: patch-src_gallium_auxiliary_util_u__format__tests.c,v 1.1 2015/04/25 11:19:18 tnn Exp $

On old NetBSD, NAN in math.h is __nanf.__val. Which is not constant.

--- src/gallium/auxiliary/util/u_format_tests.c.orig	2014-09-12 21:30:32.000000000 +0000
+++ src/gallium/auxiliary/util/u_format_tests.c
@@ -28,6 +28,10 @@
 
 #include <math.h>
 #include <float.h>
+#if defined(__NetBSD__) && __NetBSD_Version__ < 600000000
+#undef NAN
+#define NAN __builtin_nanf("")
+#endif
 
 #include "pipe/p_config.h"
 #include "u_memory.h"
