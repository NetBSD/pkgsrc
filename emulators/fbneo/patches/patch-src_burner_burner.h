$NetBSD: patch-src_burner_burner.h,v 1.1 2023/05/29 19:30:48 nia Exp $

Make the "FORCE_SYSTEM_LIBPNG" option do the unsurprising thing.

--- src/burner/burner.h.orig	2021-05-01 20:32:23.000000000 +0000
+++ src/burner/burner.h
@@ -54,6 +54,8 @@ typedef struct tagIMAGE {
 
 #if defined (INCLUDE_LIB_PNGH)
  #include "png.h"
+#else
+ #include <png.h>
 #endif
 
 // ---------------------------------------------------------------------------
