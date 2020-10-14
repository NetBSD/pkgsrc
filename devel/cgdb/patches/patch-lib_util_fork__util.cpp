$NetBSD: patch-lib_util_fork__util.cpp,v 1.1 2020/10/14 05:32:16 kamil Exp $

Make CGDB work again with GDB 8.3 and newer.
https://github.com/cgdb/cgdb/commit/00e26a33579e4b3e553d26fdbe26eb98b4b062ac

--- lib/util/fork_util.cpp.orig	2019-05-17 23:22:33.000000000 +0000
+++ lib/util/fork_util.cpp
@@ -188,7 +188,7 @@ int invoke_debugger(const char *path,
     const char *const ANNOTATE_TWO = "--annotate=2";
     const char *const GDBMI = "-i=mi2";
     const char *const SET_ANNOTATE_TWO = "set annotate 2";
-    const char *const SET_HEIGHT_ZERO = "set height 0";
+    const char *const SET_PAGINATION_OFF = "set pagination off";
     char **local_argv;
     int i, j = 0, extra = 8;
     int malloc_size = argc + extra;
@@ -213,7 +213,7 @@ int invoke_debugger(const char *path,
     local_argv[j++] = cgdb_strdup(SET_ANNOTATE_TWO);
 
     local_argv[j++] = cgdb_strdup(EX);
-    local_argv[j++] = cgdb_strdup(SET_HEIGHT_ZERO);
+    local_argv[j++] = cgdb_strdup(SET_PAGINATION_OFF);
 
     /* add the init file that the user did not type */
     if (choice == 0)
