$NetBSD: patch-sdk_src_posix_fs.cpp,v 1.2 2024/06/18 18:23:15 bsiegert Exp $

Fix build on NetBSD, use statvfs

--- sdk/src/posix/fs.cpp.orig	2024-05-17 14:19:43.000000000 +0000
+++ sdk/src/posix/fs.cpp
@@ -27,6 +27,9 @@
 #include <sys/utsname.h>
 #include <sys/ioctl.h>
 #include <sys/statvfs.h>
+#if defined(__NetBSD__)
+#define statfs statvfs
+#endif
 #include <sys/resource.h>
 #ifdef TARGET_OS_MAC
 #include "mega/osx/osxutils.h"
