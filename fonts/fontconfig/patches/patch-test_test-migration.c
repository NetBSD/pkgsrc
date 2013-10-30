$NetBSD: patch-test_test-migration.c,v 1.2 2013/10/30 23:53:10 wiz Exp $

Fix build on Solaris.
From Akira TAGOH (upstream).

--- test/test-migration.c.orig	2013-10-11 03:10:18.000000000 +0000
+++ test/test-migration.c
@@ -4,8 +4,26 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <dirent.h>
+#ifndef HAVE_STRUCT_DIRENT_D_TYPE
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <unistd.h>
+#endif
 #include <fontconfig/fontconfig.h>
 
+#ifdef HAVE_MKDTEMP
+#define fc_mkdtemp	mkdtemp
+#else
+char *
+fc_mkdtemp (char *template)
+{
+    if (!mktemp (template) || mkdir (template, 0700))
+	return NULL;
+
+    return template;
+}
+#endif
+
 FcBool
 mkdir_p(const char *dir)
 {
@@ -36,6 +54,9 @@ unlink_dirs(const char *dir)
     size_t len = strlen (dir);
     char *n = NULL;
     FcBool ret = FcTrue;
+#ifndef HAVE_STRUCT_DIRENT_D_TYPE
+    struct stat statb;
+#endif
 
     if (!d)
 	return FcFalse;
@@ -53,7 +74,17 @@ unlink_dirs(const char *dir)
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
@@ -89,7 +120,7 @@ int
 main(void)
 {
     char template[32] = "fontconfig-XXXXXXXX";
-    char *tmp = mkdtemp (template);
+    char *tmp = fc_mkdtemp (template);
     size_t len = strlen (tmp), xlen, dlen;
     char xdg[256], confd[256], fn[256], nfn[256], ud[256], nud[256];
     int ret = -1;
