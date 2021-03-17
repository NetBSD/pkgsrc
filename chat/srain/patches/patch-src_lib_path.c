$NetBSD: patch-src_lib_path.c,v 1.2 2021/03/17 15:32:24 nia Exp $

Use the Linux procfs code path for finding the executable
name as a portable fallback.

The code for other platforms is wrong.

--- src/lib/path.c.orig	2021-02-28 09:19:09.000000000 +0000
+++ src/lib/path.c
@@ -50,21 +50,20 @@
 #include <mach-o/dyld.h>
 #include <unistd.h>
 
-#elif defined __linux__
+#elif defined __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+
+#else
 #include <limits.h>
 #include <libgen.h>
 #include <unistd.h>
 
-#define PROC_SELF_EXE "/proc/self/exe"
-
-#elif defined __sun
-
+#if defined __sun
 #define PROC_SELF_EXE "/proc/self/path/a.out"
-
-#elif defined __FreeBSD__
-#include <sys/types.h>
-#include <sys/sysctl.h>
-
+#else
+#define PROC_SELF_EXE "/proc/self/exe"
+#endif
 #endif
 
 #define DEFAULT_FILE_MODE   (S_IRUSR | S_IWUSR)
@@ -371,20 +370,6 @@ char *srn_get_executable_dir() {
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
@@ -404,7 +389,7 @@ char *srn_get_executable_dir() {
     return executableDir;
 }
 
-#elif defined __FreeBSD__
+
 char *srn_get_executable_path() {
     int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
     char rawPath[PATH_MAX];
@@ -424,4 +409,18 @@ char *srn_get_executable_dir() {
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
