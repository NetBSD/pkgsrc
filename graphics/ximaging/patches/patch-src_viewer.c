$NetBSD: patch-src_viewer.c,v 1.2 2026/11/16 19:47:49 vins Exp $

SunOS needs alloca.h

--- src/viewer.c.orig	2026-08-30 08:30:08.000000000 +0000
+++ src/viewer.c
@@ -33,6 +33,9 @@
 #include <dirent.h>
 #include <unistd.h>
 #include <math.h>
+#ifdef __sun
+#include <alloca.h>
+#endif
 #include "common.h"
 #include "viewerp.h"
 #include "menu.h"
