$NetBSD: patch-src_ft2__diskop.c,v 1.4 2019/06/20 11:39:06 fox Exp $

Added <sys/types.h> / <sys/stat.h> to prevent "unknown type name"
(dev_t, ino_t and nlink_t) error from the included <fts.h>.

--- src/ft2_diskop.c.orig	2019-04-19 01:53:39.359713817 +0000
+++ src/ft2_diskop.c
@@ -15,6 +15,8 @@
 #include <direct.h>
 #include <shlobj.h> // SHGetFolderPathW()
 #else
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <fts.h> // for fts_open() and stuff in recursiveDelete()
 #include <unistd.h>
 #include <dirent.h>
