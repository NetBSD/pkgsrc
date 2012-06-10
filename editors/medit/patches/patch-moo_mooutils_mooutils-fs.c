$NetBSD: patch-moo_mooutils_mooutils-fs.c,v 1.1 2012/06/10 12:50:33 obache Exp $

* existence of sys/wait.h is not checked by configure script.
  https://sourceforge.net/tracker/?func=detail&aid=3532386&group_id=167563&atid=843451

--- moo/mooutils/mooutils-fs.c.orig	2012-03-04 11:37:37.000000000 +0000
+++ moo/mooutils/mooutils-fs.c
@@ -45,7 +45,7 @@
 #define S_IRWXU 0
 #endif
 
-#ifdef HAVE_SYS_WAIT_H
+#ifndef __WIN32__
 #include <sys/wait.h>
 #endif
 #ifdef HAVE_UNISTD_H
