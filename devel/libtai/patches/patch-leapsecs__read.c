$NetBSD: patch-leapsecs__read.c,v 1.1 2017/06/26 00:53:48 schmonz Exp $

#include <unistd.h> in leapsecs_read.c so we can read leapsecs.dat.

--- leapsecs_read.c.orig	1998-10-13 16:52:20.000000000 +0000
+++ leapsecs_read.c
@@ -2,6 +2,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <unistd.h>
 extern int errno;
 #include "tai.h"
 #include "leapsecs.h"
