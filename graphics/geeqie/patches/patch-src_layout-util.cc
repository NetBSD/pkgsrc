$NetBSD: patch-src_layout-util.cc,v 1.1 2024/03/17 13:55:10 wiz Exp $

Add header for WEXITSTATUS().

--- src/layout-util.cc.orig	2024-03-17 13:53:09.725464955 +0000
+++ src/layout-util.cc
@@ -23,6 +23,7 @@
 
 #include <dirent.h>
 #include <unistd.h>
+#include <sys/wait.h>
 
 #include <cstdio>
 #include <cstdlib>
