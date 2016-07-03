$NetBSD: patch-src_runtime_gc_c-globals-tbl.c,v 1.1 2016/07/03 19:35:36 dholland Exp $

Use standard headers.

--- src/runtime/gc/c-globals-tbl.c~	2000-06-01 18:34:03.000000000 +0000
+++ src/runtime/gc/c-globals-tbl.c
@@ -6,6 +6,7 @@
  * in the ML heap (e.g., references to C functions).
  */
 
+#include <string.h>
 #include "ml-base.h"
 #include "tags.h"
 #include "ml-values.h"
