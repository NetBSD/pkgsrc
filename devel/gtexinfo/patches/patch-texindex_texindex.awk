$NetBSD: patch-texindex_texindex.awk,v 1.2 2015/08/13 20:17:03 joerg Exp $

--- texindex/texindex.awk.orig	2015-06-18 20:04:07.000000000 +0000
+++ texindex/texindex.awk
@@ -332,7 +332,9 @@ function field_split( \
 function print_initial(initial)
 {
   if (Do_initials) {
-    if (index(Special_chars, initial) != 0)
+    if (initial == Command_char)
+      initial = "$\backslash$"
+    else if (index(Special_chars, initial) != 0)
       initial = Command_char initial
     printf("%cinitial {%s}\n",
       Command_char, initial) > Output_file
