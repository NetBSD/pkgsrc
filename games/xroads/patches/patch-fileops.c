$NetBSD: patch-fileops.c,v 1.1 2025/09/29 20:44:50 mrg Exp $

--- fileops.c.orig	1999-06-30 11:25:02.000000000 -0700
+++ fileops.c	2025-09-26 12:44:17.572457897 -0700
@@ -35,6 +35,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <limits.h>
+#include <stdlib.h>
 
 extern maze_t maze;
 extern char xrmpath[80];
