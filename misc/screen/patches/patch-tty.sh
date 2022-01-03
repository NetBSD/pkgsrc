$NetBSD: patch-tty.sh,v 1.6 2022/01/03 21:21:12 christos Exp $

Change condition for using TIOCSCTTY.

NetBSD on the netbsd-5 branch insists on a non-NULL second argument
to the realpath() function.  Make it so.

On BSD's we don't want to set CLOCAL because it prevents sending SIGHUP
on master pty close.

--- tty.sh.orig	2020-02-05 15:09:38.000000000 -0500
+++ tty.sh	2022-01-03 16:10:52.529555957 -0500
@@ -267,7 +267,13 @@
 
 IF{CS8} 	m->tio.c_cflag |= CS8;
 IF{CREAD}	m->tio.c_cflag |= CREAD;
+#ifndef BSD
+/*
+ * On BSDs definining CLOCAL disables SIGHUP on master close
+ * and we don't want that.
+ */
 IF{CLOCAL}	m->tio.c_cflag |= CLOCAL;
+#endif
 
 IF{ECHOCTL}	m->tio.c_lflag |= ECHOCTL;
 IF{ECHOKE}	m->tio.c_lflag |= ECHOKE;
@@ -784,7 +790,9 @@
   /*
    * Under BSD we have to set the controlling terminal again explicitly.
    */
-# if (defined(__FreeBSD_kernel__) || defined(__DragonFly__) || defined(__GNU__) || defined(__OpenBSD__)) && defined(TIOCSCTTY)
+# if (defined(__FreeBSD_kernel__) || defined(__DragonFly__) \
+	|| defined(__GNU__) || (BSD >= 199103) || defined(__OpenBSD__)) \
+	&& defined(TIOCSCTTY)
   ioctl(fd, TIOCSCTTY, (char *)0);
 # endif
 
@@ -1485,8 +1493,10 @@
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
