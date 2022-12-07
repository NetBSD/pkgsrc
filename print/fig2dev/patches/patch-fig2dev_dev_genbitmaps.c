$NetBSD: patch-fig2dev_dev_genbitmaps.c,v 1.1 2022/12/07 15:30:09 fcambus Exp $

Fix undefined references to `WIFEXITED' and `WEXITSTATUS'.

--- fig2dev/dev/genbitmaps.c.orig	2022-12-07 15:02:13.774357198 +0000
+++ fig2dev/dev/genbitmaps.c
@@ -36,6 +36,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <signal.h>
+#include <sys/wait.h>
 
 #include "bool.h"
 #include "fig2dev.h"	/* includes bool.h and object.h */
