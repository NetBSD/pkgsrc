$NetBSD: patch-scripts_io_strread.m,v 1.1 2014/03/06 23:06:58 jperkin Exp $

Texinfo 5.x compatibility.

--- scripts/io/strread.m.orig	2013-02-21 20:19:24.000000000 +0000
+++ scripts/io/strread.m
@@ -39,7 +39,7 @@
 ## @item %s
 ## The word is parsed as a string.
 ##
-## @itemx %f
+## @item %f
 ## @itemx %n
 ## The word is parsed as a number and converted to double.
 ##
