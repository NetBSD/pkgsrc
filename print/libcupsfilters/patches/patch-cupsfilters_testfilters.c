$NetBSD: patch-cupsfilters_testfilters.c,v 1.1 2025/08/16 00:58:19 ryoon Exp $

* For S_IRUSR.

--- cupsfilters/testfilters.c.orig	2025-03-22 18:09:20.163360870 +0000
+++ cupsfilters/testfilters.c
@@ -7,6 +7,7 @@
 #include <signal.h>
 #include <stdio.h>
 #include <string.h>
+#include <sys/stat.h>
 
 /*
  * 'remove_white_space()' - Remove white spaces from beginning and end of a string
