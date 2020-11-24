$NetBSD: patch-src_lib_path.c,v 1.1 2020/11/24 14:17:53 nia Exp $

Use the Linux code for finding the executable filename using
/proc on other OSes too.

--- src/lib/path.c.orig	2020-10-04 01:11:49.000000000 +0000
+++ src/lib/path.c
@@ -48,7 +48,7 @@
 #include <mach-o/dyld.h>
 #include <unistd.h>
 
-#elif defined __linux__
+#else
 #include <limits.h>
 #include <libgen.h>
 #include <unistd.h>
@@ -364,20 +364,6 @@ char *srn_get_executable_dir() {
     return executableDir;
 }
 
-#elif defined __linux__
-char *srn_get_executable_path() {
-   char rawPathName[PATH_MAX];
-   realpath(PROC_SELF_EXE, rawPathName);
-   return g_build_filename(rawPathName, NULL);
-}
-
-char *srn_get_executable_dir() {
-    char *exePath = srn_get_executable_path();
-    char *executableDir = g_path_get_dirname(exePath);
-    g_free(exePath);
-    return executableDir;
-}
-
 #elif defined __APPLE__
 char *srn_get_executable_path() {
     char rawPathName[PATH_MAX];
@@ -396,4 +382,18 @@ char *srn_get_executable_dir() {
     g_free(executablePath);
     return executableDir;
 }
+
+#else
+char *srn_get_executable_path() {
+   char rawPathName[PATH_MAX];
+   realpath(PROC_SELF_EXE, rawPathName);
+   return g_build_filename(rawPathName, NULL);
+}
+
+char *srn_get_executable_dir() {
+    char *exePath = srn_get_executable_path();
+    char *executableDir = g_path_get_dirname(exePath);
+    g_free(exePath);
+    return executableDir;
+}
 #endif
