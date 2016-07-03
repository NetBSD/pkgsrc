$NetBSD: patch-src_runtime_gc_heap-out-util.c,v 1.1 2016/07/03 19:35:13 dholland Exp $

Use standard headers.

--- src/runtime/gc/heap-out-util.c~	2000-06-01 18:34:03.000000000 +0000
+++ src/runtime/gc/heap-out-util.c
@@ -5,6 +5,7 @@
  * Utility routines to export (or blast) an ML heap image.
  */
 
+#include <string.h>
 #include "ml-base.h"
 #include "heap.h"
 #include "ml-values.h"
