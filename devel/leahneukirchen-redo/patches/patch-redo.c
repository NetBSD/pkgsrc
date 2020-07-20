$NetBSD: patch-redo.c,v 1.2 2020/07/20 19:46:18 schmonz Exp $

Avoid CONFLICTS with other redo implementations.
Define PATH_MAX on Illumos.

--- redo.c.orig	2020-06-26 21:46:40.000000000 +0000
+++ redo.c
@@ -34,6 +34,7 @@ todo:
 #include <errno.h>
 #include <fcntl.h>
 #include <inttypes.h>
+#include <limits.h>
 #include <stdarg.h>
 #include <stdint.h>
 #include <stdio.h>
@@ -968,20 +969,25 @@ main(int argc, char *argv[])
 
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
