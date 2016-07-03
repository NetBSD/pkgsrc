$NetBSD: patch-src_runtime_gc_mem-writer.c,v 1.1 2016/07/03 19:35:36 dholland Exp $

Use standard headers.

--- src/runtime/gc/mem-writer.c~	2000-06-01 18:34:03.000000000 +0000
+++ src/runtime/gc/mem-writer.c
@@ -5,6 +5,7 @@
  * An implementation of the abstract writers on top of memory regions.
  */
 
+#include <string.h>
 #include "ml-base.h"
 #include "writer.h"
 
