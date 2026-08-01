$NetBSD: patch-interface.c,v 1.1 2026/08/01 18:11:29 ryoon Exp $

--- interface.c.orig	2026-08-01 17:49:09.759925699 +0000
+++ interface.c
@@ -10,6 +10,7 @@
 #include <sys/types.h>
 #include <sys/time.h>
 #include <sys/param.h>
+#include <sys/wait.h>
 #include "const.h"
 #include "globals.h"
 #include "functions.h"
