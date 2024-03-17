$NetBSD: patch-src_layout-util.cc,v 1.2 2024/03/17 15:22:11 wiz Exp $

Add header for WEXITSTATUS().
https://github.com/BestImageViewer/geeqie/pull/1294

--- src/layout-util.cc.orig	2024-03-17 13:53:09.725464955 +0000
+++ src/layout-util.cc
@@ -23,6 +23,7 @@
 
 #include <dirent.h>
 #include <unistd.h>
+#include <sys/wait.h>
 
 #include <cstdio>
 #include <cstdlib>
