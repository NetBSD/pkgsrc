$NetBSD: patch-lib_long-options.c,v 1.1 2025/04/28 16:58:51 tnn Exp $

replace K&R prototypes

--- lib/long-options.c.orig	2025-04-28 16:41:33.100904926 +0000
+++ lib/long-options.c
@@ -22,6 +22,7 @@
 #endif
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <getopt.h>
 #include "long-options.h"
 
@@ -38,8 +39,8 @@ void
 parse_long_options (argc, argv,version, usage)
      int argc;
      char **argv;
-     void (*version)();
-     void (*usage)();
+     void (*version)(void);
+     void (*usage)(int);
 {
   int c;
   int saved_opterr;
@@ -60,7 +61,7 @@ parse_long_options (argc, argv,version,
 	  (*usage) (0);
 
 	case 'v':
-	  (*version) (0);
+	  (*version) ();
 	  /* printf ("%s (%s) %s\n", command_name, package, version_string); */
 	  exit (0);
 
