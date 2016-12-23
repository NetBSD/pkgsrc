$NetBSD: patch-libDeployPkg_processPosix.c,v 1.2 2016/12/23 04:11:03 ryoon Exp $

--- libDeployPkg/processPosix.c.orig	2016-09-29 10:05:27.000000000 +0000
+++ libDeployPkg/processPosix.c
@@ -28,6 +28,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/wait.h>
+#include <signal.h>
 
 #include "util.h"
 
