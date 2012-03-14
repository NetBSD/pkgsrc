$NetBSD: patch-hier.c,v 1.1 2012/03/14 23:16:29 joerg Exp $

--- hier.c.orig	2012-03-13 17:44:57.000000000 +0000
+++ hier.c
@@ -9,9 +9,6 @@ void hier()
 
   d(auto_home,"man",-1,-1,02755);
   d(auto_home,"man/man1",-1,-1,02755);
-  d(auto_home,"man/cat1",-1,-1,02755);
   c(auto_home,"man/man1","safecat.1",-1,-1,0644);
-  c(auto_home,"man/cat1","safecat.0",-1,-1,0644);
   c(auto_home,"man/man1","maildir.1",-1,-1,0644);
-  c(auto_home,"man/cat1","maildir.0",-1,-1,0644);
 }
