$NetBSD: patch-src_runtime_kernel_main.c,v 1.1 2016/07/03 19:35:36 dholland Exp $

Use standard headers.

--- src/runtime/kernel/main.c~	2005-05-05 16:25:12.000000000 +0000
+++ src/runtime/kernel/main.c
@@ -6,6 +6,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include <ctype.h>
 #include "ml-base.h"
 #include "ml-options.h"
