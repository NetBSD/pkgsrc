$NetBSD: patch-mksquashfs.c,v 1.1 2016/09/09 15:40:17 scole Exp $
Include fnm_extmatch.h

--- mksquashfs.c.orig	2014-05-12 22:18:20.000000000 +0000
+++ mksquashfs.c
@@ -76,6 +76,7 @@
 #include "read_fs.h"
 #include "restore.h"
 #include "process_fragments.h"
+#include "fnm_extmatch.h"
 
 int delete = FALSE;
 int fd;
