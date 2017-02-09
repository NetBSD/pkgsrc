$NetBSD: patch-src_gd__gd2.c,v 1.1 2017/02/09 03:27:30 minskim Exp $

--- src/gd_gd2.c.orig	2017-01-18 10:49:29.000000000 +0000
+++ src/gd_gd2.c
@@ -73,6 +73,7 @@
 #endif
 
 /* 2.0.29: no more errno.h, makes windows happy */
+#include <limits.h>
 #include <math.h>
 #include <string.h>
 #include "gd.h"
