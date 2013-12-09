$NetBSD: patch-gio_glocalfile.c,v 1.3 2013/12/09 14:46:19 wiz Exp $

Fix compilation on Solaris where O_DIRECTORY does not exist.
PR pkg/48435.

--- gio/glocalfile.c.orig	2013-11-12 05:30:22.000000000 +0000
+++ gio/glocalfile.c
@@ -2699,7 +2699,11 @@ g_local_file_measure_size_of_file (gint 
         return FALSE;
 
 #ifdef AT_FDCWD
+#ifdef O_DIRECTORY
       dir_fd = openat (parent_fd, name->data, O_RDONLY | O_DIRECTORY);
+#else
+      dir_fd = openat (parent_fd, name->data, O_RDONLY);
+#endif
       if (dir_fd < 0)
         return g_local_file_measure_size_error (state->flags, errno, name, error);
 #endif
