$NetBSD: patch-leapsecs__read.c,v 1.1 2017/09/01 03:46:36 schmonz Exp $

Fix to the included libtai, brought over from devel/libtai:

#include <unistd.h> in leapsecs_read.c so we can read leapsecs.dat.

--- leapsecs_read.c.orig	1998-11-15 02:28:23.000000000 +0000
+++ leapsecs_read.c
@@ -2,6 +2,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <unistd.h>
 extern int errno;
 #include "tai.h"
 #include "leapsecs.h"
