$NetBSD: patch-lib_ext2fs_tdb.c,v 1.2 2016/08/09 21:46:07 jdolecek Exp $

Move #include <sys/types.h> before the #define of _XOPEN_SOURCE so that
u_short etc. are being defined by it.

Fixes build on MirBSD. 

--- lib/ext2fs/tdb.c.orig	2016-06-07 05:01:19.000000000 +0000
+++ lib/ext2fs/tdb.c
@@ -36,6 +36,7 @@ Last Changed Date: 2007-06-22 13:36:10 -
 #define HAVE_UTIME_H
 #define HAVE_UTIME
 #endif
+#include <sys/types.h>
 #ifndef __FreeBSD__
 #define _XOPEN_SOURCE 600
 #endif
@@ -52,7 +53,6 @@ Last Changed Date: 2007-06-22 13:36:10 -
 #include <sys/select.h>
 #endif
 #include <sys/time.h>
-#include <sys/types.h>
 #include <time.h>
 #ifdef HAVE_UTIME_H
 #include <utime.h>
