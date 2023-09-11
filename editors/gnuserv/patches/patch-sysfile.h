$NetBSD: patch-sysfile.h,v 1.1 2023/09/11 21:18:49 vins Exp $

This hack is not really needed.

--- sysfile.h.orig	2007-10-20 22:23:32.000000000 +0000
+++ sysfile.h
@@ -422,14 +422,6 @@ extern int h_errno;
 int dup2 (int oldd, int newd);
 #endif
 
-#ifndef HAVE_STRERROR
-/* X11R6 defines strerror as a macro */
-# ifdef strerror
-# undef strerror
-# endif
-const char *strerror (int);
-#endif
-
 
 
 /* 
