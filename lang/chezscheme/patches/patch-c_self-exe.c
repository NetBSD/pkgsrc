$NetBSD: patch-c_self-exe.c,v 1.1 2024/05/02 13:22:34 pho Exp $

/proc/curproc/file is not a symlink on NetBSD. Use sysctl instead.

TODO: Upstream this

--- c/self-exe.c.orig	2024-05-02 12:42:04.735939925 +0000
+++ c/self-exe.c
@@ -187,6 +187,29 @@ static char *get_self_path_platform() {
 }
 #endif
 
+#if defined(__NetBSD__)
+#include <limits.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#define HAVE_GET_SELF_PATH_PLATFORM
+static char *get_self_path_platform() {
+  const int mib[4] = {
+    CTL_KERN,
+    KERN_PROC_ARGS,
+    -1, /* current process */
+    KERN_PROC_PATHNAME
+  };
+  size_t path_len = PATH_MAX;
+  char path[path_len];
+  if (sysctl(mib, sizeof(mib) / sizeof(int), path, &path_len, NULL, 0) == 0) {
+    path[path_len] = '\0';
+    return copy_string(path);
+  }
+  return NULL;
+}
+#endif
+
 #if defined(__sun__) && defined(__svr4__)
 #define HAVE_GET_SELF_PATH_PLATFORM
 static char *get_self_path_platform() {
@@ -203,7 +226,7 @@ static char *get_self_path_platform() {
 static char *get_self_path_platform() { return copy_string("/proc/self/exe"); }
 #endif
 
-#if defined(__NetBSD__) || defined(__minix) || defined(__DragonFly__) ||       \
+#if defined(__minix) || defined(__DragonFly__) ||       \
     defined(__FreeBSD_kernel__) || defined(_AIX)
 #define HAVE_GET_SELF_PATH_PLATFORM
 static char *get_self_path_platform() { return copy_string("/proc/curproc/file"); }
