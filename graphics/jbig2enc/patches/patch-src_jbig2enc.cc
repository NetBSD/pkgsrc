$NetBSD: patch-src_jbig2enc.cc,v 1.1 2023/01/30 07:55:18 adam Exp $

Fix build with Leptonica >=1.83
https://github.com/agl/jbig2enc/pull/78

--- src/jbig2enc.cc.orig	2023-01-27 09:23:35.000000000 +0000
+++ src/jbig2enc.cc
@@ -24,6 +24,10 @@
 #include <string.h>
 
 #include <leptonica/allheaders.h>
+#if (LIBLEPT_MAJOR_VERSION == 1 && LIBLEPT_MINOR_VERSION >= 83) || LIBLEPT_MAJOR_VERSION > 1
+#include "leptonica/pix_internal.h"
+#include "leptonica/array_internal.h"
+#endif
 
 #include <math.h>
 #if defined(sun)
@@ -206,7 +210,11 @@ unite_templates(struct jbig2ctx *ctx,
         numaSetValue(ctx->classer->naclass, i, new_representant);
       }
     }
+#if (LIBLEPT_MAJOR_VERSION == 1 && LIBLEPT_MINOR_VERSION >= 83) || LIBLEPT_MAJOR_VERSION > 1
+    ctx->classer->pixat->pix[new_representant]->refcount += ctx->classer->pixat->pix[second_template]->refcount;
+#else
     pixChangeRefcount(ctx->classer->pixat->pix[new_representant],pixGetRefcount(ctx->classer->pixat->pix[second_template]));
+#endif
   }
   return 0;
 }
