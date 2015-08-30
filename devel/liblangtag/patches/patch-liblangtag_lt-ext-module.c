$NetBSD: patch-liblangtag_lt-ext-module.c,v 1.1 2015/08/30 16:17:27 richard Exp $
workaround for erroneous readdir_r usage reported upstream as found on SunOS
--- liblangtag/lt-ext-module.c.orig	2015-01-05 07:30:05.000000000 +0000
+++ liblangtag/lt-ext-module.c
@@ -24,6 +24,7 @@
 #if HAVE_LIBGEN_H
 #include <libgen.h>
 #endif
+#include <stddef.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -604,19 +605,21 @@ lt_ext_modules_load(void)
 
 		dir = opendir(path);
 		if (dir) {
-			struct dirent dent, *dresult;
-			size_t len;
+			struct dirent *dent, *p;
 
-			while (1) {
-				if (readdir_r(dir, &dent, &dresult) || dresult == NULL)
-					break;
-
-				len = strlen(dent.d_name);
+			while ((dent = readdir (dir))) {
+				size_t len = strlen (dent->d_name);
+				size_t dentlen = offsetof (struct dirent, d_name) + len + 1;
+
+				dentlen = ((dentlen + ALIGNOF_VOID_P - 1) & ~(ALIGNOF_VOID_P - 1));
+				p = (struct dirent *)malloc(dentlen);
+				memcpy(p, dent, dentlen);
 				if (len > suffix_len &&
-				    lt_strcmp0(&dent.d_name[len - suffix_len],
+				    lt_strcmp0(&(p->d_name[len - suffix_len]),
 					       "." LT_MODULE_SUFFIX) == 0) {
-					lt_ext_module_new(dent.d_name);
+					lt_ext_module_new(p->d_name);
 				}
+				free(p);
 			}
 			closedir(dir);
 		}
