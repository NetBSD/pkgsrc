$NetBSD: patch-platform_libpicofe_posix.h,v 1.1 2024/04/26 09:04:31 nia Exp $

NetBSD support.

--- platform/libpicofe/posix.h.orig	2024-04-16 19:15:33.864037786 +0000
+++ platform/libpicofe/posix.h
@@ -2,7 +2,7 @@
 #define LIBPICOFE_POSIX_H
 
 /* define POSIX stuff: dirent, scandir, getcwd, mkdir */
-#if defined(__linux__) || defined(__MINGW32__)
+#if defined(__linux__) || defined(__MINGW32__) || defined(__unix__)
 
 #include <dirent.h>
 #include <unistd.h>
