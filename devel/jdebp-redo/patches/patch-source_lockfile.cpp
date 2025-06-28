$NetBSD: patch-source_lockfile.cpp,v 1.1 2025/06/28 02:53:31 schmonz Exp $

Avoid missing POSIX constants and openat() on Illumos.

--- source/lockfile.cpp.orig	2025-06-28 02:47:42.729689254 +0000
+++ source/lockfile.cpp
@@ -3,6 +3,8 @@ For copyright and licensing terms, see t
 // **************************************************************************
 */
 
+#define _ATFILE_SOURCE
+#include <fcntl.h>
 #include <sys/types.h>
 #include <sys/file.h>
 #include <unistd.h>
