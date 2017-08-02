$NetBSD: patch-src_rrd__list.c,v 1.1 2017/08/02 03:13:54 maya Exp $

Need limits.h for PATH_MAX

--- src/rrd_list.c.orig	2017-05-16 12:26:46.000000000 +0000
+++ src/rrd_list.c
@@ -3,6 +3,7 @@
 #include <string.h>
 #include <glob.h>
 #include <dirent.h>
+#include <limits.h>
 #include <sys/types.h>
 
 #include "rrd_tool.h"
