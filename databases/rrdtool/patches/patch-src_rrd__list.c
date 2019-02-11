$NetBSD: patch-src_rrd__list.c,v 1.2 2019/02/11 08:22:45 adam Exp $

Need limits.h for PATH_MAX

--- src/rrd_list.c.orig	2019-02-04 17:42:30.000000000 +0000
+++ src/rrd_list.c
@@ -14,6 +14,7 @@
 #endif
 #include <dirent.h>
 #endif
+#include <limits.h>
 #include <sys/types.h>
 
 #include "rrd_tool.h"
