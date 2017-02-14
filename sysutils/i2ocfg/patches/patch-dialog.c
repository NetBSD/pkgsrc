$NetBSD: patch-dialog.c,v 1.1 2017/02/14 21:21:56 joerg Exp $

--- dialog.c.orig	2017-02-09 17:23:32.088667999 +0000
+++ dialog.c
@@ -35,6 +35,7 @@
 #include <sys/uio.h>
 #include <sys/device.h>
 #include <sys/mman.h>
+#include <sys/stat.h>
 
 #include <err.h>
 #include <errno.h>
