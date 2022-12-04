$NetBSD: patch-src_a68g_options.c,v 1.2 2022/12/04 17:11:13 rhialto Exp $

* Enable compiler for *BSD.

--- src/a68g/options.c.orig	2022-02-01 20:45:41.000000000 +0000
+++ src/a68g/options.c
@@ -548,7 +548,7 @@ BOOL_T set_options (OPTION_LIST_T * i, B
 #endif
             }
             if (eq (q, "linux")) {
-#if !defined (BUILD_LINUX)
+#if (!defined (BUILD_LINUX) && !defined(BUILD_BSD))
               io_close_tty_line ();
               WRITE (STDOUT_FILENO, "linux required - exiting graciously");
               a68_exit (EXIT_SUCCESS);
