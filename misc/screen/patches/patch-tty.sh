$NetBSD: patch-tty.sh,v 1.5 2020/02/07 12:19:00 ryoon Exp $

Change condition for using TIOCSCTTY.

NetBSD on the netbsd-5 branch insists on a non-NULL second argument
to the realpath() function.  Make it so.

--- tty.sh.orig	2020-02-05 20:09:38.000000000 +0000
+++ tty.sh
@@ -784,7 +784,9 @@ int fgtty(int fd)
   /*
    * Under BSD we have to set the controlling terminal again explicitly.
    */
-# if (defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__GNU__) || defined(__OpenBSD__)) && defined(TIOCSCTTY)
+# if (defined(__FreeBSD_kernel__) || defined(__DragonFly__) \
+	|| defined(__GNU__) || (BSD >= 199103) || defined(__OpenBSD__)) \
+	&& defined(TIOCSCTTY)
   ioctl(fd, TIOCSCTTY, (char *)0);
 # endif
 
@@ -1485,8 +1487,10 @@ int CheckTtyname (char *tty)
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
