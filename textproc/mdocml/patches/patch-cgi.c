$NetBSD: patch-cgi.c,v 1.1 2013/10/11 14:45:18 wiz Exp $

SunOS fix.

--- cgi.c.orig	2013-10-05 14:09:07.000000000 +0000
+++ cgi.c
@@ -33,6 +33,12 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#if defined(__sun)
+/* for stat() */
+#include <fcntl.h>
+#include <sys/types.h>
+#include <sys/stat.h>
+#endif
 
 #include "apropos_db.h"
 #include "mandoc.h"
@@ -42,7 +48,7 @@
 #include "manpath.h"
 #include "mandocdb.h"
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__sun)
 # include <db_185.h>
 #else
 # include <db.h>
@@ -1097,11 +1103,20 @@ static int
 pathstop(DIR *dir)
 {
 	struct dirent	*d;
+#if defined(__sun)
+  struct stat sb;
+#endif
 
-	while (NULL != (d = readdir(dir)))
+	while (NULL != (d = readdir(dir))) {
+#if defined(__sun)
+    stat(d->d_name, &sb);
+    if (S_IFREG & sb.st_mode)
+#else
 		if (DT_REG == d->d_type)
+#endif
 			if (0 == strcmp(d->d_name, "catman.conf"))
 				return(1);
+  }
 
 	return(0);
 }
@@ -1118,6 +1133,9 @@ pathgen(DIR *dir, char *path, struct req
 	DIR		*cd;
 	int		 rc;
 	size_t		 sz, ssz;
+#if defined(__sun)
+  struct stat sb;
+#endif
 
 	sz = strlcat(path, "/", PATH_MAX);
 	if (sz >= PATH_MAX) {
@@ -1133,7 +1151,13 @@ pathgen(DIR *dir, char *path, struct req
 
 	rc = 0;
 	while (0 == rc && NULL != (d = readdir(dir))) {
-		if (DT_DIR != d->d_type || strcmp(d->d_name, "etc"))
+#if defined(__sun)
+    stat(d->d_name, &sb);
+    if (!(S_IFDIR & sb.st_mode)
+#else
+		if (DT_DIR != d->d_type
+#endif
+        || strcmp(d->d_name, "etc"))
 			continue;
 
 		path[(int)sz] = '\0';
@@ -1182,7 +1206,13 @@ pathgen(DIR *dir, char *path, struct req
 
 	rewinddir(dir);
 	while (NULL != (d = readdir(dir))) {
-		if (DT_DIR != d->d_type || '.' == d->d_name[0])
+#if defined(__sun)
+    stat(d->d_name, &sb);
+    if (!(S_IFDIR & sb.st_mode)
+#else
+		if (DT_DIR != d->d_type
+#endif
+        || '.' == d->d_name[0])
 			continue;
 
 		path[(int)sz] = '\0';
