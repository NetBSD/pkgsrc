$NetBSD: patch-test_test-migration.c,v 1.1 2013/10/21 08:21:04 wiz Exp $

Fix build on Solaris.
From Akira TAGOH (upstream).

--- test/test-migration.c.orig	2013-10-11 03:10:18.000000000 +0000
+++ test/test-migration.c
@@ -4,6 +4,11 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <dirent.h>
+#ifndef HAVE_STRUCT_DIRENT_D_TYPE
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <unistd.h>
+#endif
 #include <fontconfig/fontconfig.h>
 
 FcBool
@@ -36,6 +41,9 @@ unlink_dirs(const char *dir)
     size_t len = strlen (dir);
     char *n = NULL;
     FcBool ret = FcTrue;
+#ifndef HAVE_STRUCT_DIRENT_D_TYPE
+    struct stat statb;
+#endif
 
     if (!d)
 	return FcFalse;
@@ -53,7 +61,17 @@ unlink_dirs(const char *dir)
 	strcpy (n, dir);
 	n[len] = '/';
 	strcpy (&n[len + 1], e->d_name);
+#ifdef HAVE_STRUCT_DIRENT_D_TYPE
 	if (e->d_type == DT_DIR)
+#else
+	if (stat (n, &statb) == -1)
+	{
+		fprintf (stderr, "E: %s\n", n);
+		ret = FcFalse;
+		break;
+	}
+	if (S_ISDIR (statb.st_mode))
+#endif
 	{
 	    if (!unlink_dirs (n))
 	    {
