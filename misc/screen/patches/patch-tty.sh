$NetBSD: patch-tty.sh,v 1.2 2015/09/01 13:34:47 kim Exp $

Change condition for using TIOCSCTTY.

NetBSD on the netbsd-5 branch insists on a non-NULL second argument
to the realpath() function.  Make it so.

--- tty.sh.orig	2015-06-28 21:22:56.000000000 +0000
+++ tty.sh	2015-09-01 12:46:28.000000000 +0000
@@ -812,7 +812,8 @@
   /*
    * Under BSD we have to set the controlling terminal again explicitly.
    */
-# if (defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__GNU__)) && defined(TIOCSCTTY)
+# if (defined(__FreeBSD_kernel__) || defined(__DragonFly__) \
+      || defined(__GNU__) || (BSD >= 199103)) && defined(TIOCSCTTY)
   ioctl(fd, TIOCSCTTY, (char *)0);
 # endif
 
@@ -1508,8 +1509,10 @@
   struct stat st;
   char * real;
   int rc;
+  char *ttynamebuf;
 
-  real = realpath(tty, NULL);
+  ttynamebuf = malloc(MAXPATHLEN);
+  real = realpath(tty, ttynamebuf);
   if (!real)
     return -1;
 
