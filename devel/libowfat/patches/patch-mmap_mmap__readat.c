$NetBSD: patch-mmap_mmap__readat.c,v 1.2 2023/11/09 19:26:00 schmonz Exp $

Fix Illumos build.

--- mmap/mmap_readat.c.orig	2019-04-23 13:25:27.000000000 +0000
+++ mmap/mmap_readat.c
@@ -3,6 +3,7 @@
 
 #include <sys/types.h>
 #ifndef _WIN32
+#include <sys/time.h>
 #include <sys/stat.h>
 #include <unistd.h>
 #include <fcntl.h>
