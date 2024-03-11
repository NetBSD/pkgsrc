$NetBSD: patch-sdk_src_posix_fs.cpp,v 1.1 2024/03/11 07:49:12 wiz Exp $

* Add NetBSD support

--- sdk/src/posix/fs.cpp.orig	2023-05-02 16:07:05.000000000 +0000
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
