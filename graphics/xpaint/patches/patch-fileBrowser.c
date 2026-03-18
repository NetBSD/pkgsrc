$NetBSD: patch-fileBrowser.c,v 1.2 2026/03/18 15:14:35 nia Exp $

Suppport dirent(3) if defined.

--- fileBrowser.c.orig	2021-01-21 21:38:23.000000000 +0000
+++ fileBrowser.c
@@ -17,4 +17,5 @@
 
 #include <ctype.h>
+#include <strings.h>
 #include <X11/StringDefs.h>
 #include <X11/Intrinsic.h>
@@ -49,5 +50,5 @@ extern Xaw3dXftData *xaw3dxft_data;
 #include <sys/types.h>
 #include <sys/stat.h>
-#if defined(SYSV) || defined(SVR4) || defined(__CYGWIN__) || defined(__VMS )
+#if HAVE_DIRENT_H
 #include <dirent.h>
 #else
@@ -564,5 +565,5 @@ setCWD(arg_t * arg, char *dir)
 {
     DIR *dirp;
-#if defined(SYSV) || defined(SVR4) || defined(__alpha) || defined(__CYGWIN__)
+#if HAVE_DIRENT_H
     struct dirent *e;
 #else
