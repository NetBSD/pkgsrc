$NetBSD: patch-src_ft2__diskop.c,v 1.2 2019/03/21 10:16:40 fox Exp $

Added <sys/types.h> / <sys/stat.h> to prevent "unknown type name"
(dev_t, ino_t and nlink_t) error from the included <fts.h>.

--- src/ft2_diskop.c.orig	2019-03-18 16:59:48.000000000 +0000
+++ src/ft2_diskop.c
@@ -12,6 +12,8 @@
 #include <windows.h>
 #include <direct.h>
 #else
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <fts.h> // for fts_open() and stuff in recursiveDelete()
 #include <unistd.h>
 #include <dirent.h>
