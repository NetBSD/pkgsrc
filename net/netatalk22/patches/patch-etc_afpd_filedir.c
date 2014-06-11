$NetBSD: patch-etc_afpd_filedir.c,v 1.1 2014/06/11 11:03:56 hauke Exp $

--- etc/afpd/filedir.c.orig	2013-07-23 09:10:55.000000000 +0000
+++ etc/afpd/filedir.c
@@ -372,7 +372,7 @@ static int moveandrename(const struct vo
 #ifdef HAVE_ATFUNCS
         opened = of_findnameat(sdir_fd, &path);
 #else
-        opened = of_findname(&path);
+        opened = of_findname(vol, &path);
 #endif /* HAVE_ATFUNCS */
 
         if (opened) {
