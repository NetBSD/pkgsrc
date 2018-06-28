$NetBSD: patch-gmetad_rrd__helpers.c,v 1.2 2018/06/28 01:05:01 bacon Exp $

# Portability

--- gmetad/rrd_helpers.c.orig	2015-07-01 19:49:35.000000000 +0000
+++ gmetad/rrd_helpers.c
@@ -2,6 +2,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#ifndef __linux__
+#include <sys/filio.h>
+#endif
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
