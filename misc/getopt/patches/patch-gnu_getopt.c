$NetBSD: patch-gnu_getopt.c,v 1.2 2026/05/19 07:57:55 jperkin Exp $

* Include <string.h> for strlen(3)
* Fix for modern C.

--- gnu/getopt.c.orig	2014-11-19 21:39:47.000000000 +0000
+++ gnu/getopt.c
@@ -40,6 +40,7 @@
 #endif
 
 #include <stdio.h>
+#include <string.h>
 
 /* Comment out all this code if we are using the GNU C Library, and are not
    actually compiling the library itself.  This code is part of the GNU C
@@ -207,12 +208,10 @@ static char *posixly_correct;
 /* Avoid depending on library functions or files
    whose names are inconsistent.  */
 
-char *getenv ();
+char *getenv (const char *);
 
 static char *
-my_index (str, chr)
-     const char *str;
-     int chr;
+my_index (const char *str, int chr)
 {
   while (*str)
     {
@@ -300,8 +299,7 @@ static void exchange (char **);
 #endif
 
 static void
-exchange (argv)
-     char **argv;
+exchange (char **argv)
 {
   int bottom = first_nonopt;
   int middle = last_nonopt;
@@ -385,10 +383,7 @@ exchange (argv)
 static const char *_getopt_initialize (int, char *const *, const char *);
 #endif
 static const char *
-_getopt_initialize (argc, argv, optstring)
-     int argc;
-     char *const *argv;
-     const char *optstring;
+_getopt_initialize (int argc, char *const *argv, const char *optstring)
 {
   /* Start processing options with ARGV-element 1 (since ARGV-element 0
      is the program name); the sequence of previously skipped
@@ -510,13 +505,7 @@ _getopt_initialize (argc, argv, optstrin
    long-named options.  */
 
 int
-_getopt_internal (argc, argv, optstring, longopts, longind, long_only)
-     int argc;
-     char *const *argv;
-     const char *optstring;
-     const struct option *longopts;
-     int *longind;
-     int long_only;
+_getopt_internal (int argc, char *const *argv, const char *optstring, const struct option *longopts, int *longind, int long_only)
 {
   optarg = NULL;
 
@@ -695,7 +684,7 @@ _getopt_internal (argc, argv, optstring,
 		optarg = nameend + 1;
 	      else
 		{
-		  if (opterr)
+		  if (opterr) {
 		   if (argv[optind - 1][1] == '-')
 		    /* --option */
 		    fprintf (stderr,
@@ -706,6 +695,7 @@ _getopt_internal (argc, argv, optstring,
 		    fprintf (stderr,
 		     _("%s: option `%c%s' doesn't allow an argument\n"),
 		     argv[0], argv[optind - 1][0], pfound->name);
+		  }
 
 		  nextchar += strlen (nextchar);
 
@@ -964,10 +954,7 @@ _getopt_internal (argc, argv, optstring,
 }
 
 int
-getopt (argc, argv, optstring)
-     int argc;
-     char *const *argv;
-     const char *optstring;
+getopt (int argc, char *const *argv, const char *optstring)
 {
   return _getopt_internal (argc, argv, optstring,
 			   (const struct option *) 0,
