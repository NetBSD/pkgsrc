$NetBSD: patch-gnu_getopt1.c,v 1.1 2026/05/19 07:57:55 jperkin Exp $

Fix for modern C.

--- gnu/getopt1.c.orig	2026-05-19 07:36:43.996213093 +0000
+++ gnu/getopt1.c
@@ -63,12 +63,7 @@
 #endif
 
 int
-getopt_long (argc, argv, options, long_options, opt_index)
-     int argc;
-     char *const *argv;
-     const char *options;
-     const struct option *long_options;
-     int *opt_index;
+getopt_long (int argc, char *const *argv, const char *options, const struct option *long_options, int *opt_index)
 {
   return _getopt_internal (argc, argv, options, long_options, opt_index, 0);
 }
@@ -79,12 +74,7 @@ getopt_long (argc, argv, options, long_o
    instead.  */
 
 int
-getopt_long_only (argc, argv, options, long_options, opt_index)
-     int argc;
-     char *const *argv;
-     const char *options;
-     const struct option *long_options;
-     int *opt_index;
+getopt_long_only (int argc, char *const *argv, const char *options, const struct option *long_options, int *opt_index)
 {
   return _getopt_internal (argc, argv, options, long_options, opt_index, 1);
 }
