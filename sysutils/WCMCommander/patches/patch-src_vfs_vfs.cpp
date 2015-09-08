$NetBSD: patch-src_vfs_vfs.cpp,v 1.1 2015/09/08 13:13:20 wiz Exp $

Use BSD headers on NetBSD, and use statvfs (statfs was removed).

--- src/vfs/vfs.cpp.orig	2015-04-24 21:50:22.000000000 +0000
+++ src/vfs/vfs.cpp
@@ -1113,9 +1113,12 @@ FSWin32Net::~FSWin32Net()
 // for statfs()
 #ifdef __linux__
 #  include <sys/statfs.h>
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #  include <sys/param.h>
 #  include <sys/mount.h>
+#  if defined(__NetBSD__)
+#    define statfs statvfs
+#  endif
 #endif
 
 #ifdef __linux__
