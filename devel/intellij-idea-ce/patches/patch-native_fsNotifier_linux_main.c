$NetBSD: patch-native_fsNotifier_linux_main.c,v 1.1 2013/11/24 10:44:34 ryoon Exp $

* Use mntent compat from sysutils/fam

--- native/fsNotifier/linux/main.c.orig	2013-11-23 23:41:25.000000000 +0000
+++ native/fsNotifier/linux/main.c
@@ -18,7 +18,11 @@
 
 #include <errno.h>
 #include <limits.h>
+#if defined(__linux__)
 #include <mntent.h>
+#else
+#include "fam-mntent.h"
+#endif
 #include <paths.h>
 #include <stdarg.h>
 #include <stdlib.h>
