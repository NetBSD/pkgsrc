$NetBSD: patch-src_ucm_parser.c,v 1.5 2017/03/28 09:10:57 jperkin Exp $

* SunOS has no dirent d_type
* Include limits.h for PATH_MAX.

--- src/ucm/parser.c.orig	2016-12-20 14:43:20.000000000 +0000
+++ src/ucm/parser.c
@@ -32,6 +32,7 @@
 
 #include "ucm_local.h"
 #include <dirent.h>
+#include <limits.h>
 
 /** The name of the environment variable containing the UCM directory */
 #define ALSA_CONFIG_UCM_VAR "ALSA_CONFIG_UCM"
@@ -1368,9 +1369,17 @@ int uc_mgr_import_master_config(snd_use_
 
 static int filename_filter(const struct dirent *dirent)
 {
+#ifdef __sun
+	struct stat s;
+#endif
 	if (dirent == NULL)
 		return 0;
+#ifdef __sun
+	stat(dirent->d_name, &s);
+	if (s.st_mode & S_IFDIR) {
+#else
 	if (dirent->d_type == DT_DIR) {
+#endif
 		if (dirent->d_name[0] == '.') {
 			if (dirent->d_name[1] == '\0')
 				return 0;
