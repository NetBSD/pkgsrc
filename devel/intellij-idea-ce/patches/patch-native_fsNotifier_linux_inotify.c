$NetBSD: patch-native_fsNotifier_linux_inotify.c,v 1.1 2013/11/24 10:44:34 ryoon Exp $

* Non-Linux (*BSD?) support

--- native/fsNotifier/linux/inotify.c.orig	2013-11-23 23:48:48.000000000 +0000
+++ native/fsNotifier/linux/inotify.c
@@ -18,7 +18,11 @@
 
 #include <dirent.h>
 #include <errno.h>
+#if defined(__linux__)
 #include <linux/limits.h>
+#else
+#include <limits.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
