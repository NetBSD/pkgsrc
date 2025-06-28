$NetBSD: patch-redo.c,v 1.3 2025/06/28 03:05:35 schmonz Exp $

Avoid CONFLICTS with other redo implementations.
Define PATH_MAX and dprintf() on Illumos.

--- redo.c.orig	2020-10-01 16:15:36.000000000 +0000
+++ redo.c
@@ -34,6 +34,7 @@ todo:
 #include <errno.h>
 #include <fcntl.h>
 #include <inttypes.h>
+#include <limits.h>
 #include <stdarg.h>
 #include <stdint.h>
 #include <stdio.h>
@@ -194,6 +195,26 @@ int level = -1;
 int implicit_jobs = 1;
 int kflag, jflag, xflag, fflag, sflag;
 
+#ifdef __sun
+#include <stdarg.h>
+static int
+dprintf(int fd, const char *format, ...)
+{
+	va_list args;
+	char buffer[1024];
+	int ret;
+
+	va_start(args, format);
+	ret = vsnprintf(buffer, sizeof(buffer), format, args);
+	va_end(args);
+
+	if (ret > 0) {
+		write(fd, buffer, ret);
+	}
+	return ret;
+}
+#endif
+
 static void
 redo_ifcreate(int fd, char *target)
 {
@@ -969,20 +990,25 @@ main(int argc, char *argv[])
 
 	dir_fd = keepdir();
 
-	if (strcmp(program, "redo") == 0) {
+	if (strcmp(program, "redo") == 0
+	 || strcmp(program, "leahneukirchen-redo") == 0) {
 		fflag = 1;
 		redo_ifchange(argc, argv);
 		procure();
-	} else if (strcmp(program, "redo-ifchange") == 0) {
+	} else if (strcmp(program, "redo-ifchange") == 0
+					|| strcmp(program, "leahneukirchen-redo-ifchange") == 0) {
 		redo_ifchange(argc, argv);
 		record_deps(argc, argv);
 		procure();
-	} else if (strcmp(program, "redo-ifcreate") == 0) {
+	} else if (strcmp(program, "redo-ifcreate") == 0
+					|| strcmp(program, "leahneukirchen-redo-ifcreate") == 0) {
 		for (i = 0; i < argc; i++)
 			redo_ifcreate(dep_fd, argv[i]);
-	} else if (strcmp(program, "redo-always") == 0) {
+	} else if (strcmp(program, "redo-always") == 0
+					|| strcmp(program, "leahneukirchen-redo-always") == 0) {
 		dprintf(dep_fd, "!\n");
-	} else if (strcmp(program, "redo-hash") == 0) {
+	} else if (strcmp(program, "redo-hash") == 0
+					|| strcmp(program, "leahneukirchen-redo-hash") == 0) {
 		for (i = 0; i < argc; i++)
 			write_dep(1, argv[i]);
 	} else {
