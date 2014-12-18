$NetBSD: patch-notmuch-dump.c,v 1.1 2014/12/18 12:26:51 joerg Exp $

Avoid depending on very recent zlib.

--- notmuch-dump.c.orig	2014-12-15 20:12:50.000000000 +0000
+++ notmuch-dump.c
@@ -177,7 +177,7 @@ notmuch_database_dump (notmuch_database_
 	}
     }
 
-    if (gzclose_w (output) != Z_OK) {
+    if (gzclose(output) != Z_OK) {
 	fprintf (stderr, "Error closing %s: %s\n", name_for_error,
 		 gzerror (output, NULL));
 	ret = EXIT_FAILURE;
@@ -196,7 +196,7 @@ notmuch_database_dump (notmuch_database_
     }
  DONE:
     if (ret != EXIT_SUCCESS && output)
-	(void) gzclose_w (output);
+	(void) gzclose(output);
 
     if (ret != EXIT_SUCCESS && output_file_name)
 	(void) unlink (tempname);
