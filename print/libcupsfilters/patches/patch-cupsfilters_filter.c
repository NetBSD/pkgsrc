$NetBSD: patch-cupsfilters_filter.c,v 1.1 2025/08/16 00:58:19 ryoon Exp $

* For S_IRUSR.

--- cupsfilters/filter.c.orig	2025-03-22 18:08:00.199525771 +0000
+++ cupsfilters/filter.c
@@ -18,6 +18,7 @@
 #include <math.h>
 #include <errno.h>
 #include <signal.h>
+#include <sys/stat.h>
 #include <sys/wait.h>
 #include <cups/file.h>
 #include <cups/array.h>
