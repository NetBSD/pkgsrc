$NetBSD: patch-lib_utils_base.c,v 1.1 2012/05/24 15:22:18 marino Exp $

--- lib/utils_base.c.orig	2010-07-27 20:47:16.000000000 +0000
+++ lib/utils_base.c
@@ -28,6 +28,9 @@
 #include <stdarg.h>
 #include "utils_base.h"
 #include <fcntl.h>
+#ifdef __DragonFly__
+#include <sys/stat.h>
+#endif
 
 #define np_free(ptr) { if(ptr) { free(ptr); ptr = NULL; } }
 
