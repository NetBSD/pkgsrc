$NetBSD: patch-debugfs_debugfs.c,v 1.2 2017/12/08 08:12:58 adam Exp $

Fix build on SunOS.

--- debugfs/debugfs.c.orig	2017-10-16 05:45:45.000000000 +0000
+++ debugfs/debugfs.c
@@ -29,6 +29,9 @@ extern char *optarg;
 #ifdef HAVE_SYS_SYSMACROS_H
 #include <sys/sysmacros.h>
 #endif
+#ifdef __sun
+#include <sys/mkdev.h>
+#endif
 
 #include "debugfs.h"
 #include "uuid/uuid.h"
