$NetBSD: patch-notmuch-config.c,v 1.1 2014/01/09 12:15:23 wiz Exp $

NULL as second argument for realpath() is only supported in glibc
and POSIX 2008. Work around this.  See BUGS section for problems:
http://man7.org/linux/man-pages/man3/realpath.3.html

--- notmuch-config.c.orig	2013-12-31 00:39:25.000000000 +0000
+++ notmuch-config.c
@@ -23,6 +23,8 @@
 #include <pwd.h>
 #include <netdb.h>
 #include <assert.h>
+#include <sys/param.h>
+#include <stdlib.h>
 
 static const char toplevel_config_comment[] =
     " .notmuch-config - Configuration file for the notmuch mail system\n"
@@ -444,7 +446,7 @@ int
 notmuch_config_save (notmuch_config_t *config)
 {
     size_t length;
-    char *data, *filename;
+    char *data, filename[MAXPATHLEN];
     GError *error = NULL;
 
     data = g_key_file_to_data (config->key_file, &length, NULL);
@@ -454,15 +456,9 @@ notmuch_config_save (notmuch_config_t *c
     }
 
     /* Try not to overwrite symlinks. */
-    filename = realpath (config->filename, NULL);
-    if (! filename) {
+    if (! realpath (config->filename, filename)) {
 	if (errno == ENOENT) {
-	    filename = strdup (config->filename);
-	    if (! filename) {
-		fprintf (stderr, "Out of memory.\n");
-		g_free (data);
-		return 1;
-	    }
+	    strncpy(filename, config->filename, MAXPATHLEN);
 	} else {
 	    fprintf (stderr, "Error canonicalizing %s: %s\n", config->filename,
 		     strerror (errno));
@@ -480,12 +476,10 @@ notmuch_config_save (notmuch_config_t *c
 		     filename, error->message);
 	}
 	g_error_free (error);
-	free (filename);
 	g_free (data);
 	return 1;
     }
 
-    free (filename);
     g_free (data);
     return 0;
 }
