$NetBSD: patch-vncviewer_misc.c,v 1.1 2025/10/12 22:35:32 mrg Exp $

Add missing header for wait(2) prototype.


--- vncviewer/misc.c.orig	2003-01-14 23:58:32.000000000 -0800
+++ vncviewer/misc.c	2025-10-12 15:24:52.037316337 -0700
@@ -22,6 +22,7 @@
  */
 
 #include <vncviewer.h>
+#include <sys/wait.h>
 #include <signal.h>
 #include <fcntl.h>
 
