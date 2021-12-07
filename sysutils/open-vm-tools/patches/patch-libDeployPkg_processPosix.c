$NetBSD: patch-libDeployPkg_processPosix.c,v 1.3 2021/12/07 18:25:46 adam Exp $

--- libDeployPkg/processPosix.c.orig	2021-08-31 09:03:13.000000000 +0000
+++ libDeployPkg/processPosix.c
@@ -29,6 +29,7 @@
 #include <fcntl.h>
 #include <sys/wait.h>
 #include <stdlib.h>
+#include <signal.h>
 
 #include "util.h"
 
