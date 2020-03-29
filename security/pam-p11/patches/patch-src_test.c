$NetBSD: patch-src_test.c,v 1.1 2020/03/29 02:18:56 manu Exp $
--- src/test.c.orig	2020-03-28 02:23:37.173089076 +0000
+++ src/test.c	2020-03-28 02:23:57.222211243 +0000
@@ -19,8 +19,12 @@
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
 
+#ifdef __NetBSD__
+#define NO_STATIC_MODULES
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
