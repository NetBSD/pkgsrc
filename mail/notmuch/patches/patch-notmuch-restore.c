$NetBSD: patch-notmuch-restore.c,v 1.1 2014/12/18 12:26:51 joerg Exp $

Avoid depending on very recent zlib.

--- notmuch-restore.c.orig	2014-12-15 20:12:30.000000000 +0000
+++ notmuch-restore.c
@@ -312,7 +312,7 @@ notmuch_restore_command (notmuch_config_
     if (notmuch)
 	notmuch_database_destroy (notmuch);
 
-    if (input && gzclose_r (input)) {
+    if (input && gzclose(input)) {
 	fprintf (stderr, "Error closing %s: %s\n",
 		 name_for_error, gzerror (input, NULL));
 	ret = EXIT_FAILURE;
