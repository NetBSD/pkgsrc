$NetBSD: patch-src_pidfile.c,v 1.2 2023/12/20 17:05:01 wiz Exp $

dprintf is not available on SunOS (illumos)

--- src/pidfile.c.orig	Fri Oct 15 10:11:49 2021
+++ src/pidfile.c	Fri Oct 15 10:11:58 2021
@@ -29,6 +29,23 @@
 
 static const char *pidfile_path = PR_PID_FILE_PATH;
 
+#if defined(__sun)
+#include <stdarg.h>
+
+int dprintf(int fd, const char *restrict format, ...) {
+    va_list ap;
+    FILE *f = fdopen(fd, "w");
+    if (!f) {
+        return -1;
+    }
+    va_start(ap, format);
+    int result = fprintf(f, format, ap);
+    va_end(ap);
+
+    return result;
+}
+#endif
+
 const char *pr_pidfile_get(void) {
   return pidfile_path;
 }
