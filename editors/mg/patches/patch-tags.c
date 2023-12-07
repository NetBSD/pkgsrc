$NetBSD: patch-tags.c,v 1.1 2023/12/07 23:57:25 tnn Exp $

Use local copy of tree.h on macOS

--- tags.c.orig	2023-12-07 23:36:46.013657675 +0000
+++ tags.c
@@ -8,7 +8,11 @@
 
 #include <sys/queue.h>
 #include <sys/stat.h>
+#if defined(__APPLE__)
+#include "tree.h"
+#else
 #include <sys/tree.h>
+#endif
 #include <sys/types.h>
 #include <ctype.h>
 #include <err.h>
