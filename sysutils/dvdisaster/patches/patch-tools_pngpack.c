$NetBSD: patch-tools_pngpack.c,v 1.1.2.2 2015/04/30 01:47:33 hiramatsu Exp $

--- tools/pngpack.c.orig	2015-04-26 12:04:56.000000000 +0000
+++ tools/pngpack.c
@@ -22,6 +22,7 @@
 #include <getopt.h>
 #include <sys/stat.h>
 #include <stdlib.h>
+#include <string.h>
 
 #include "md5.h"
 #include "pngio.h"
