$NetBSD: patch-tty.c,v 1.1 2015/01/12 14:24:40 he Exp $

NetBSD on the netbsd-5 branch insists on a non-NULL second argument
to the realpath() function.  Make it so.

--- tty.c.orig	2015-01-12 09:30:15.000000000 +0000
+++ tty.c
@@ -1833,8 +1833,10 @@ char *tty;
   struct stat st;
   char * real;
   int rc;
+  char *ttynamebuf;
 
-  real = realpath(tty, NULL);
+  ttynamebuf = malloc(MAXPATHLEN);
+  real = realpath(tty, ttynamebuf);
   if (!real)
     return -1;
 
