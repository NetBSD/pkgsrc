$NetBSD: patch-process.c,v 1.1 2023/07/23 10:17:23 bsiegert Exp $

signal.h is required to use the kill function.

--- process.c.orig	2012-07-02 14:50:46.000000000 +0000
+++ process.c
@@ -28,6 +28,7 @@
 #include <sys/wait.h>
 #include <errno.h>
 #include <stdlib.h>
+#include <signal.h>
 
 int kidgeneration = 0;
 
