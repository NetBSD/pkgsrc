$NetBSD: patch-fig2dev_dev_readeps.c,v 1.1 2022/12/07 15:30:09 fcambus Exp $

Fix undefined references to `WIFEXITED' and `WEXITSTATUS'.

--- fig2dev/dev/readeps.c.orig	2022-12-07 15:02:30.866814168 +0000
+++ fig2dev/dev/readeps.c
@@ -29,6 +29,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
+#include <sys/wait.h>
 
 #include "fig2dev.h"	/* includes bool.h and object.h */
 //#include "object.h"
