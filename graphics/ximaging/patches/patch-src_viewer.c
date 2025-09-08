$NetBSD: patch-src_viewer.c,v 1.1 2025/09/08 07:22:18 vins Exp $

SunOS needs alloca.h

--- src/viewer.c.orig	2025-09-08 07:16:15.989814141 +0000
+++ src/viewer.c
@@ -33,6 +33,9 @@
 #include <dirent.h>
 #include <unistd.h>
 #include <math.h>
+#ifdef __sun
+#include <alloca.h>
+#endif
 #include "common.h"
 #include "viewer_i.h"
 #include "menu.h"
