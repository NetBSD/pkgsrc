$NetBSD: patch-etc_afpd_filedir.c,v 1.1 2013/07/23 13:28:17 hauke Exp $

--- etc/afpd/filedir.c.orig	2013-07-23 09:10:55.000000000 +0000
+++ etc/afpd/filedir.c
@@ -372,7 +372,7 @@ static int moveandrename(const struct vo
 #ifdef HAVE_ATFUNCS
         opened = of_findnameat(sdir_fd, &path);
 #else
-        opened = of_findname(&path);
+        opened = of_findname(sdir_fd, &path);
 #endif /* HAVE_ATFUNCS */
 
         if (opened) {
