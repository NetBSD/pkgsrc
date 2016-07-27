$NetBSD: patch-gobble.c,v 1.1 2016/07/27 20:37:27 kamil Exp $

Fix K&R code.

--- gobble.c.orig	2016-07-27 20:12:55.340913088 +0000
+++ gobble.c
@@ -22,8 +22,11 @@ char gobble_RCSid[] = "Revision: 1.4 $";
 
 #include "agm.h"
 
-gobble_file (filename, command)
-    char *filename, *command;
+#include <stdlib.h>
+#include <unistd.h>
+
+void
+gobble_file (char *filename, char *command)
 {
   FILE *fp;
   int is_a_tty2 = 0;
@@ -81,4 +84,3 @@ gobble_file (filename, command)
   }
   if (notquiet) printf (" %d words\n", wordcount - before_count);
 }
-
