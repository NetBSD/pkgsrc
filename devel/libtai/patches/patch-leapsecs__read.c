$NetBSD: patch-leapsecs__read.c,v 1.3 2026/03/17 14:58:30 nia Exp $

#include <unistd.h> in leapsecs_read.c so we can read leapsecs.dat.
Respect PKG_SYSCONFDIR.

--- leapsecs_read.c.orig	1998-10-13 16:52:20.000000000 +0000
+++ leapsecs_read.c
@@ -2,6 +2,8 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <unistd.h>
+#include <stdlib.h>
 extern int errno;
 #include "tai.h"
 #include "leapsecs.h"
@@ -18,7 +20,7 @@ int leapsecs_read()
   int i;
   struct tai u;
 
-  fd = open("/etc/leapsecs.dat",O_RDONLY | O_NDELAY);
+  fd = open("@PKG_SYSCONFDIR@/leapsecs.dat",O_RDONLY | O_NDELAY);
   if (fd == -1) {
     if (errno != ENOENT) return -1;
     if (leapsecs) free(leapsecs);
