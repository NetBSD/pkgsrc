$NetBSD: patch-src_a68g_a68g-options.c,v 1.1 2023/03/29 10:11:13 rhialto Exp $

* Enable compiler for *BSD.

--- src/a68g/a68g-options.c.orig	2023-03-19 20:10:12.000000000 +0000
+++ src/a68g/a68g-options.c
@@ -552,7 +552,7 @@ BOOL_T set_options (OPTION_LIST_T * i, B
 #endif
             }
             if (eq (q, "linux")) {
-#if !defined (BUILD_LINUX)
+#if (!defined (BUILD_LINUX) && !defined(BUILD_BSD))
               io_close_tty_line ();
               WRITE (STDOUT_FILENO, "linux required - exiting graciously");
               a68_exit (EXIT_SUCCESS);
