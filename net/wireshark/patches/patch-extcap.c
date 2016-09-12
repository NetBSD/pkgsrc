$NetBSD: patch-extcap.c,v 1.1 2016/09/12 10:59:55 wiz Exp $

Fix linking on NetBSD.

--- extcap.c.orig	2016-09-07 16:59:05.000000000 +0000
+++ extcap.c
@@ -35,6 +35,8 @@
 #else
 /* Include for unlink */
 #include <unistd.h>
+/* for WEXITSTATUS */
+#include <sys/wait.h>
 #endif
 
 #include <glib.h>
