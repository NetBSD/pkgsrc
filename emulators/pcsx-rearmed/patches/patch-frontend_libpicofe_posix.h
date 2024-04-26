$NetBSD: patch-frontend_libpicofe_posix.h,v 1.1 2024/04/26 09:10:10 nia Exp $

NetBSD support.

--- frontend/libpicofe/posix.h.orig	2024-04-16 09:47:48.307454271 +0000
+++ frontend/libpicofe/posix.h
@@ -2,7 +2,7 @@
 #define LIBPICOFE_POSIX_H
 
 /* define POSIX stuff: dirent, scandir, getcwd, mkdir */
-#if defined(__linux__) || defined(__MINGW32__)
+#if defined(__unix__)
 
 #include <dirent.h>
 #include <unistd.h>
