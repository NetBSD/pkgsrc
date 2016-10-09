$NetBSD: patch-libDeployPkg_processPosix.c,v 1.1 2016/10/09 03:41:56 ryoon Exp $

--- libDeployPkg/processPosix.c.orig	2016-02-16 20:06:47.000000000 +0000
+++ libDeployPkg/processPosix.c
@@ -22,6 +22,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/wait.h>
+#include <signal.h>
 
 // vmware headers
 #include "util.h"
