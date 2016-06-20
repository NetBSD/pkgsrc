$NetBSD: patch-tty.sh,v 1.3 2016/06/20 16:04:44 ryoon Exp $

Change condition for using TIOCSCTTY.

NetBSD on the netbsd-5 branch insists on a non-NULL second argument
to the realpath() function.  Make it so.

--- tty.sh.orig	2016-06-19 19:41:03.000000000 +0000
+++ tty.sh
@@ -813,7 +813,8 @@ int fd;
   /*
    * Under BSD we have to set the controlling terminal again explicitly.
    */
-# if (defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__GNU__)) && defined(TIOCSCTTY)
+# if (defined(__FreeBSD_kernel__) || defined(__DragonFly__) \
+      || defined(__GNU__) || (BSD >= 199103)) && defined(TIOCSCTTY)
   ioctl(fd, TIOCSCTTY, (char *)0);
 # endif
 
@@ -1510,8 +1511,10 @@ char *tty;
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
