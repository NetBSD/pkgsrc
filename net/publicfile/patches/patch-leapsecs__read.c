$NetBSD: patch-leapsecs__read.c,v 1.1 2013/05/23 14:57:32 joerg Exp $

--- leapsecs_read.c.orig	1999-11-09 07:23:46.000000000 +0000
+++ leapsecs_read.c
@@ -1,8 +1,10 @@
+#include <unistd.h>
+#include <stdlib.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
-extern int errno;
+#include <errno.h>
 #include "tai.h"
 #include "leapsecs.h"
 
