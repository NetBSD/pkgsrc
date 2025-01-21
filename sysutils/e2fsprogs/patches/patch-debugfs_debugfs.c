$NetBSD: patch-debugfs_debugfs.c,v 1.3 2025/01/21 18:13:57 triaxx Exp $

Fix build on SunOS.

--- debugfs/debugfs.c.orig	2017-10-16 05:45:45.000000000 +0000
+++ debugfs/debugfs.c
@@ -30,6 +30,9 @@ extern char *optarg;
 #ifdef HAVE_SYS_SYSMACROS_H
 #include <sys/sysmacros.h>
 #endif
+#ifdef __sun
+#include <sys/mkdev.h>
+#endif
 
 #include "debugfs.h"
 #include "uuid/uuid.h"
