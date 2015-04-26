$NetBSD: patch-tools_decimate.c,v 1.1 2015/04/26 13:30:58 joerg Exp $

--- tools/decimate.c.orig	2015-04-26 12:06:48.000000000 +0000
+++ tools/decimate.c
@@ -21,6 +21,7 @@
 #include <math.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 #include "pngio.h"
 #include "memory.h"
