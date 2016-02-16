$NetBSD: patch-gmetad_rrd__helpers.c,v 1.1 2016/02/16 12:48:18 fhajny Exp $

Portability.

--- gmetad/rrd_helpers.c.orig	2015-07-01 19:49:35.000000000 +0000
+++ gmetad/rrd_helpers.c
@@ -2,6 +2,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/filio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
