$NetBSD: patch-src_runtime_c-libs_smlnj-runtime_gc-ctl.c,v 1.1 2016/07/03 19:35:36 dholland Exp $

Use standard headers.

--- src/runtime/c-libs/smlnj-runtime/gc-ctl.c~	2005-05-05 16:25:12.000000000 +0000
+++ src/runtime/c-libs/smlnj-runtime/gc-ctl.c
@@ -5,6 +5,7 @@
  * General interface for GC control functions.
  */
 
+#include <string.h>
 #include "ml-base.h"
 #include "ml-values.h"
 #include "ml-state.h"
