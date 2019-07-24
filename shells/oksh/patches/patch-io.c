$NetBSD: patch-io.c,v 1.1 2019/07/24 11:15:41 maya Exp $

--- io.c.orig	2019-04-10 23:55:43.000000000 +0000
+++ io.c
@@ -10,6 +10,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <string.h>
+#include <stdlib.h>
 #include <unistd.h>
 
 #include "sh.h"
