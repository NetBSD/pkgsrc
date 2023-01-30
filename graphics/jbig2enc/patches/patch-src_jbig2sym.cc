$NetBSD: patch-src_jbig2sym.cc,v 1.1 2023/01/30 07:55:18 adam Exp $

Fix build with Leptonica >=1.83
https://github.com/agl/jbig2enc/pull/78

--- src/jbig2sym.cc.orig	2023-01-27 09:25:22.000000000 +0000
+++ src/jbig2sym.cc
@@ -29,6 +29,10 @@
 #include <stdio.h>
 
 #include <leptonica/allheaders.h>
+#if (LIBLEPT_MAJOR_VERSION == 1 && LIBLEPT_MINOR_VERSION >= 83) || LIBLEPT_MAJOR_VERSION > 1
+#include "leptonica/pix_internal.h"
+#include "leptonica/array_internal.h"
+#endif
 
 #include <math.h>
 
