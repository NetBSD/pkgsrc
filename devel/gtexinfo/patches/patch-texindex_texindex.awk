$NetBSD: patch-texindex_texindex.awk,v 1.1 2015/07/07 11:38:40 joerg Exp $

--- texindex/texindex.awk.orig	2015-06-18 20:04:07.000000000 +0000
+++ texindex/texindex.awk
@@ -333,7 +333,7 @@ function print_initial(initial)
 {
   if (Do_initials) {
     if (index(Special_chars, initial) != 0)
-      initial = Command_char initial
+      initial = Command_char initial "{}"
     printf("%cinitial {%s}\n",
       Command_char, initial) > Output_file
   }
