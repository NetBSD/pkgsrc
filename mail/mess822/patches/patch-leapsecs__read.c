$NetBSD: patch-leapsecs__read.c,v 1.1 2017/05/26 14:34:43 schmonz Exp $

Fix to the included libtai, brought over from devel/libtai:

#include <unistd.h> in leapsecs_read.c so we can read leapsecs.dat.

--- leapsecs_read.c.orig	1998-09-04 22:33:37.000000000 -0400
+++ leapsecs_read.c
@@ -2,6 +2,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <unistd.h>
 extern int errno;
 #include "tai.h"
 #include "leapsecs.h"
