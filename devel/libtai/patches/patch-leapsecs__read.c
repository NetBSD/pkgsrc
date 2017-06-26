$NetBSD: patch-leapsecs__read.c,v 1.2 2017/06/26 01:06:08 schmonz Exp $

#include <unistd.h> in leapsecs_read.c so we can read leapsecs.dat.
Respect PKG_SYSCONFDIR.

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
@@ -18,7 +19,7 @@ int leapsecs_read()
   int i;
   struct tai u;
 
-  fd = open("/etc/leapsecs.dat",O_RDONLY | O_NDELAY);
+  fd = open("@PKG_SYSCONFDIR@/leapsecs.dat",O_RDONLY | O_NDELAY);
   if (fd == -1) {
     if (errno != ENOENT) return -1;
     if (leapsecs) free(leapsecs);
