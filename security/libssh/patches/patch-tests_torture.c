$NetBSD: patch-tests_torture.c,v 1.2 2026/07/23 09:25:56 wiz Exp $

Fix build on NetBSD 8.1: Don't try to use PATH_MAX without #include <limits.h>

--- tests/torture.c.orig	2026-07-16 10:56:26.000000000 +0000
+++ tests/torture.c
@@ -29,6 +29,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <signal.h>
+#include <limits.h>
 
 #ifndef _WIN32
 # include <dirent.h>
