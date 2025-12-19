$NetBSD: patch-examples_pathutils.c,v 1.1 2025/12/19 11:00:46 nia Exp $

Include <strings.h> for rindex(3).

--- examples/pathutils.c.orig	2025-12-19 10:32:25.953254312 +0000
+++ examples/pathutils.c
@@ -24,6 +24,7 @@
 #include <stdlib.h>
 #include <limits.h>
 #include <string.h>
+#include <strings.h>
 #include <libgen.h>
 
 /* Find the folder_id of a given path
