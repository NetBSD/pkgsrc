$NetBSD: patch-src_ft2__diskop.c,v 1.1 2018/12/01 18:20:09 fox Exp $

Added <sys/types.h> / <sys/stat.h> to prevent "unknown type name"
(dev_t, ino_t and nlink_t) error from the included <fts.h>.

--- src/ft2_diskop.c.orig	2018-11-23 13:36:02.000000000 +0000
+++ src/ft2_diskop.c
@@ -12,6 +12,8 @@
 #include <windows.h>
 #include <direct.h>
 #else
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <fts.h> /* for fts_open() and stuff in recursiveDelete() */
 #include <unistd.h>
 #include <dirent.h>
