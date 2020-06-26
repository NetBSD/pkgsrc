$NetBSD: patch-mmap_mmap__readat.c,v 1.1 2020/06/26 19:21:52 schmonz Exp $

Fix Illumos build.

--- mmap/mmap_readat.c.orig	2016-09-16 16:22:00.000000000 +0000
+++ mmap/mmap_readat.c
@@ -4,6 +4,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 #ifndef __MINGW32__
+#include <sys/time.h>
 #include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
