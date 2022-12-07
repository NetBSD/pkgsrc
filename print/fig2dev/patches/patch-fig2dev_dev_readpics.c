$NetBSD: patch-fig2dev_dev_readpics.c,v 1.1 2022/12/07 15:30:09 fcambus Exp $

Fix undefined references to `WIFEXITED' and `WEXITSTATUS'.

--- fig2dev/dev/readpics.c.orig	2022-12-07 15:02:25.050115348 +0000
+++ fig2dev/dev/readpics.c
@@ -31,6 +31,7 @@
 #include <string.h>
 #include <unistd.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 
 #include "messages.h"
 #include "xtmpfile.h"
