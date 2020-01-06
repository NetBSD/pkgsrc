$NetBSD: patch-tests_torture.c,v 1.1 2020/01/06 12:04:13 pho Exp $

Fix build on NetBSD 8.1: Don't try to use PATH_MAX without #include <limits.h>

--- tests/torture.c.orig	2020-01-06 12:01:16.440174806 +0000
+++ tests/torture.c
@@ -29,6 +29,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <signal.h>
+#include <limits.h>
 
 #ifndef _WIN32
 # include <dirent.h>
