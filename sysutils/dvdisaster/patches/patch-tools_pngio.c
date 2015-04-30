$NetBSD: patch-tools_pngio.c,v 1.1.2.2 2015/04/30 01:47:33 hiramatsu Exp $

--- tools/pngio.c.orig	2015-04-26 12:05:25.000000000 +0000
+++ tools/pngio.c
@@ -20,6 +20,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <sys/stat.h>
 
 #include "pngio.h"
