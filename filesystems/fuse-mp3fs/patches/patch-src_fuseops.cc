$NetBSD: patch-src_fuseops.cc,v 1.1 2021/12/01 14:35:15 pho Exp $

Hunk #0:
    <fuse_common.h> is not meant to be directly #include'd by user
    code. It's only an implementation detail, and librefuse doesn't
    provide one.

--- src/fuseops.cc.orig	2021-12-01 13:29:28.302797012 +0000
+++ src/fuseops.cc
@@ -26,7 +26,6 @@
 #include <dirent.h>
 #include <fcntl.h>
 #include <fuse.h>
-#include <fuse_common.h>
 #include <sys/stat.h>
 #include <sys/statvfs.h>
 #include <unistd.h>
