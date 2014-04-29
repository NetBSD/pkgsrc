$NetBSD: patch-scheme.c,v 1.1 2014/04/29 19:18:16 agc Exp $

Fix the location of the init file

--- scheme.c	2014/04/29 17:24:27	1.1
+++ scheme.c	2014/04/29 17:24:58
@@ -100,7 +100,7 @@
 #endif
 
 #ifndef InitFile
-# define InitFile "init.scm"
+# define InitFile "@PREFIX@" "/share/tinyscheme/" "init.scm"
 #endif
 
 #ifndef FIRST_CELLSEGS
