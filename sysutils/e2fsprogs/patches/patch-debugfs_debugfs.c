$NetBSD: patch-debugfs_debugfs.c,v 1.1 2017/09/21 09:48:56 jperkin Exp $

Fix build on SunOS.

--- debugfs/debugfs.c.orig	2016-09-02 04:17:32.000000000 +0000
+++ debugfs/debugfs.c
@@ -26,6 +26,9 @@ extern char *optarg;
 #include <errno.h>
 #endif
 #include <fcntl.h>
+#ifdef __sun
+#include <sys/mkdev.h>
+#endif
 
 #include "debugfs.h"
 #include "uuid/uuid.h"
