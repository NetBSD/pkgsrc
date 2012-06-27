$NetBSD: patch-lib_ext2fs_tdb.c,v 1.1 2012/06/27 08:52:05 bsiegert Exp $

--- lib/ext2fs/tdb.c.orig	Tue Dec 13 04:47:53 2011
+++ lib/ext2fs/tdb.c
@@ -36,6 +36,7 @@ Last Changed Date: 2007-06-22 13:36:10 -
 #define HAVE_UTIME_H
 #define HAVE_UTIME
 #endif
+#include <sys/types.h>
 #define _XOPEN_SOURCE 600
 
 #include <unistd.h>
@@ -49,7 +50,6 @@ Last Changed Date: 2007-06-22 13:36:10 -
 #include <sys/select.h>
 #endif
 #include <sys/time.h>
-#include <sys/types.h>
 #include <time.h>
 #ifdef HAVE_UTIME_H
 #include <utime.h>
