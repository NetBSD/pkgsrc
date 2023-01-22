$NetBSD: patch-fileBrowser.c,v 1.1 2023/01/22 17:41:52 vins Exp $

Suppport dirent(3) if defined.

--- fileBrowser.c.orig	2021-01-21 22:38:23.000000000 +0100
+++ fileBrowser.c	2021-05-19 10:27:34.463903000 +0200
@@ -48,7 +48,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#if defined(SYSV) || defined(SVR4) || defined(__CYGWIN__) || defined(__VMS )
+#if HAVE_DIRENT_H
 #include <dirent.h>
 #else
 #include <sys/dir.h>
@@ -563,7 +563,7 @@
 setCWD(arg_t * arg, char *dir)
 {
     DIR *dirp;
-#if defined(SYSV) || defined(SVR4) || defined(__alpha) || defined(__CYGWIN__)
+#if HAVE_DIRENT_H
     struct dirent *e;
 #else
     struct direct *e;
