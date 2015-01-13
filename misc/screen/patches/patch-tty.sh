$NetBSD: patch-tty.sh,v 1.1 2015/01/13 08:27:28 he Exp $

Change condition for using TIOCSCTTY.

NetBSD on the netbsd-5 branch insists on a non-NULL second argument
to the realpath() function.  Make it so.

--- tty.sh.orig	2014-04-26 16:29:40.000000000 +0000
+++ tty.sh
@@ -812,7 +812,8 @@ int fd;
   /*
    * Under BSD we have to set the controlling terminal again explicitly.
    */
-# if (defined(__FreeBSD_kernel__) || defined(__GNU__)) && defined(TIOCSCTTY)
+# if (defined(__FreeBSD_kernel__) || defined(__GNU__) || (BSD >= 199103)) \
+  && defined(TIOCSCTTY)
   ioctl(fd, TIOCSCTTY, (char *)0);
 # endif
 
@@ -1508,8 +1509,10 @@ char *tty;
   struct stat st;
   char * real;
   int rc;
+  char *ttynamebuf;
 
-  real = realpath(tty, NULL);
+  ttynamebuf = malloc(MAXPATHLEN);
+  real = realpath(tty, ttynamebuf);
   if (!real)
     return -1;
 
