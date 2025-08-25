$NetBSD: patch-src_init__queue.c,v 1.1 2025/08/25 20:03:22 ktnb Exp $

NetBSD requires stdarg to get va_list

--- src/init_queue.c.orig	2025-01-09 14:41:43.000000000 +0000
+++ src/init_queue.c
@@ -10,6 +10,9 @@
 
 #include <stdint.h>
 #include <stdlib.h>
+#if defined(__NetBSD__)
+#include <stdarg.h>
+#endif
 
 #include "line_info.h"
 #include "toxic.h"
