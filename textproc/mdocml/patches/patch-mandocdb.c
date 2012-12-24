$NetBSD: patch-mandocdb.c,v 1.2 2012/12/24 13:40:18 jperkin Exp $

--- mandocdb.c.orig	2011-10-08 20:07:22.000000000 +0000
+++ mandocdb.c
@@ -29,12 +29,16 @@
 #include <stdlib.h>
 #include <string.h>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__sun)
 # include <db_185.h>
 #else
 # include <db.h>
 #endif
 
+#if defined(__sun)
+# include <sys/stat.h>
+#endif
+
 #include "man.h"
 #include "mdoc.h"
 #include "mandoc.h"
@@ -1223,7 +1227,15 @@ ofile_dirbuild(const char *dir, int verb
 
 	while (NULL != (dp = readdir(d))) {
 		fn = dp->d_name;
+#if defined(__sun)
+		struct stat s;
+		stat(dp->d_name, &s);
+#endif
+#if !defined(__sun)
 		if (DT_DIR == dp->d_type) {
+#else
+		if (!(s.st_mode & S_IFDIR)) {
+#endif
 			if (0 == strcmp(".", fn))
 				continue;
 			if (0 == strcmp("..", fn))
@@ -1244,7 +1256,11 @@ ofile_dirbuild(const char *dir, int verb
 			fprintf(stderr, "%s: Path too long\n", dir);
 			return(0);
 		}
+#if !defined(__sun)
 		if (DT_REG != dp->d_type)
+#else
+		if (!(s.st_mode & S_IFREG))
+#endif
 			continue;
 
 		if (0 == strcmp(MANDOC_DB, fn) ||
