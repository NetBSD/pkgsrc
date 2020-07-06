$NetBSD: patch-redo.c,v 1.1 2020/07/06 15:27:19 schmonz Exp $

Avoid CONFLICTS with other redo implementations.

--- redo.c.orig	2018-07-08 21:49:57.000000000 +0000
+++ redo.c
@@ -974,20 +974,25 @@ main(int argc, char *argv[])
 
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
