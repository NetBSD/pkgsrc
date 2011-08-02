$NetBSD: patch-lib_replace_test_os2__delete.c,v 1.1 2011/08/02 14:05:27 taca Exp $

Workaround for NetBSD 5.99.54.

--- lib/replace/test/os2_delete.c.orig	2009-09-30 12:21:56.000000000 +0000
+++ lib/replace/test/os2_delete.c
@@ -103,6 +103,7 @@ int test_readdir_os2_delete(void)
 	while (1) {
 		int n = os2_delete(d);
 		if (n == 0) break;
+		if (test_readdir_os2_delete_ret != 0) break; /* if FAILED */
 		total_deleted += n;
 	}
 	closedir(d);
