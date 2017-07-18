$NetBSD: patch-tty.sh,v 1.4 2017/07/18 23:02:18 kim Exp $

Change condition for using TIOCSCTTY.

NetBSD on the netbsd-5 branch insists on a non-NULL second argument
to the realpath() function.  Make it so.

--- tty.sh.orig	2017-07-10 19:26:25.000000000 +0000
+++ tty.sh	2017-07-18 22:40:56.000000000 +0000
@@ -813,7 +813,8 @@
   /*
    * Under BSD we have to set the controlling terminal again explicitly.
    */
-# if (defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__GNU__)) && defined(TIOCSCTTY)
+# if (defined(__FreeBSD_kernel__) || defined(__DragonFly__) \
+      || defined(__GNU__) || (BSD >= 199103)) && defined(TIOCSCTTY)
   ioctl(fd, TIOCSCTTY, (char *)0);
 # endif
 
@@ -1521,8 +1522,10 @@
   char realbuf[PATH_MAX];
   const char *real;
   int rc;
+  char *ttynamebuf;
 
-  real = realpath(tty, realbuf);
+  ttynamebuf = malloc(MAXPATHLEN);
+  real = realpath(tty, ttynamebuf);
   if (!real)
     return -1;
   realbuf[sizeof(realbuf)-1]='\0';
