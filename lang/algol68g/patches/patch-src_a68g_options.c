$NetBSD: patch-src_a68g_options.c,v 1.1 2022/03/02 01:41:34 ryoon Exp $

* Enable compiler for *BSD.

--- src/a68g/options.c.orig	2022-02-01 20:45:41.000000000 +0000
+++ src/a68g/options.c
@@ -544,7 +544,7 @@ BOOL_T set_options (OPTION_LIST_T * i, B
 #endif
             }
             if (eq (q, "linux")) {
-#if !defined (BUILD_LINUX)
+#if (!defined (BUILD_LINUX) && !defined(BUILD_BSD))
               io_close_tty_line ();
               WRITE (STDOUT_FILENO, "linux required - exiting graciously");
               a68_exit (EXIT_SUCCESS);
@@ -701,7 +701,7 @@ BOOL_T set_options (OPTION_LIST_T * i, B
         }
 // COMPILE and NOCOMPILE switch on/off compilation.
         else if (eq (p, "Compile")) {
-#if defined (BUILD_LINUX)
+#if defined (BUILD_LINUX) || defined(BUILD_BSD)
           OPTION_COMPILE (&A68_JOB) = A68_TRUE;
           OPTION_COMPILE_CHECK (&A68_JOB) = A68_TRUE;
           if (OPTION_OPT_LEVEL (&A68_JOB) < OPTIMISE_1) {
@@ -745,7 +745,7 @@ BOOL_T set_options (OPTION_LIST_T * i, B
         }
 // RUN-SCRIPT runs a compiled .sh script.
         else if (eq (p, "RUN-SCRIPT")) {
-#if defined (BUILD_LINUX)
+#if defined (BUILD_LINUX) || defined(BUILD_BSD)
           FORWARD (i);
           if (i != NO_OPTION_LIST) {
             if (!name_set) {
@@ -766,7 +766,7 @@ BOOL_T set_options (OPTION_LIST_T * i, B
         }
 // RUN-QUOTE-SCRIPT runs a compiled .sh script.
         else if (eq (p, "RUN-QUOTE-SCRIPT")) {
-#if defined (BUILD_LINUX)
+#if defined (BUILD_LINUX) || defined(BUILD_BSD)
           FORWARD (i);
           if (i != NO_OPTION_LIST) {
             if (!name_set) {
