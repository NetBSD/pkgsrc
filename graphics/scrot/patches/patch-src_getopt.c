$NetBSD: patch-src_getopt.c,v 1.1 2019/08/18 16:52:03 fox Exp $

1. Adds missing string.h header unconditionally, this is needed
   for proper builds since it is used by getopt functions.

   Upstream bug report: https://github.com/resurrecting-open-source-projects/scrot/issues/26

2. Adds brackets for "if" to prevent ambigious "else"
   (-Wparentheses)

--- src/getopt.c.orig	2019-08-18 15:26:09.139597715 +0000
+++ src/getopt.c
@@ -76,6 +76,8 @@
 #endif
 #endif
 
+#include <string.h>
+
 #ifndef _
 /* This is for other GNU distributions with internationalized messages.
    When compiling libc, the _ macro is predefined.  */
@@ -692,6 +696,7 @@ _getopt_internal(argc, argv, optstring, 
             else
             {
                if (opterr)
+	         {
                   if (argv[optind - 1][1] == '-')
                      /* --option */
                      fprintf(stderr,
@@ -704,5 +709,6 @@ _getopt_internal(argc, argv, optstring, 
                              _
                              ("%s: option `%c%s' doesn't allow an argument\n"),
                              argv[0], argv[optind - 1][0], pfound->name);
+	         }
 
                nextchar += strlen(nextchar);
