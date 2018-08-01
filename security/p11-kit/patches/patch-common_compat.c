$NetBSD: patch-common_compat.c,v 1.1 2018/08/01 19:18:19 jperkin Exp $

Avoid /proc section on Darwin.

--- common/compat.c.orig	2018-05-30 13:40:36.000000000 +0000
+++ common/compat.c
@@ -910,6 +910,7 @@ fdwalk (int (* cb) (void *data, int fd),
 	struct rlimit rl;
 #endif
 
+#if !defined(__APPLE__)
 	dir = opendir ("/proc/self/fd");
 	if (dir != NULL) {
 		while ((de = readdir (dir)) != NULL) {
@@ -932,6 +933,7 @@ fdwalk (int (* cb) (void *data, int fd),
 		closedir (dir);
 		return res;
 	}
+#endif
 
 	/* No /proc, brute force */
 #ifdef HAVE_SYS_RESOURCE_H
