$NetBSD: patch-src_systems.h,v 1.1 2021/09/14 13:32:50 schmonz Exp $

Apply upstream patch 32517af7 to check for st_mtim in struct stat.
Fixes macOS build.

--- src/systems.h.orig	2021-08-10 12:13:24.000000000 +0000
+++ src/systems.h
@@ -52,6 +52,13 @@
 # define STATBLKSIZE(st) 1024
 #endif
 
+#if ! HAVE_STRUCT_STAT_ST_MTIM
+# if HAVE_STRUCT_STAT_ST_MTIMESPEC
+#   define st_mtim st_mtimespec
+#   define HAVE_STRUCT_STAT_ST_MTIM 1
+# endif
+#endif
+
 #ifndef STDERR_FILENO
 # define STDERR_FILENO 2
 #endif
