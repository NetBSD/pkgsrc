$NetBSD: patch-hier.c,v 1.2 2016/04/01 11:20:58 jperkin Exp $

Use PKGMANDIR.

--- hier.c.orig	2001-04-14 11:09:54.000000000 +0000
+++ hier.c
@@ -7,11 +7,8 @@ void hier()
   c(auto_home,"bin","safecat",-1,-1,0755);
   c(auto_home,"bin","maildir",-1,-1,0755);
 
-  d(auto_home,"man",-1,-1,02755);
-  d(auto_home,"man/man1",-1,-1,02755);
-  d(auto_home,"man/cat1",-1,-1,02755);
-  c(auto_home,"man/man1","safecat.1",-1,-1,0644);
-  c(auto_home,"man/cat1","safecat.0",-1,-1,0644);
-  c(auto_home,"man/man1","maildir.1",-1,-1,0644);
-  c(auto_home,"man/cat1","maildir.0",-1,-1,0644);
+  d(auto_home,"@PKGMANDIR@",-1,-1,02755);
+  d(auto_home,"@PKGMANDIR@/man1",-1,-1,02755);
+  c(auto_home,"@PKGMANDIR@/man1","safecat.1",-1,-1,0644);
+  c(auto_home,"@PKGMANDIR@/man1","maildir.1",-1,-1,0644);
 }
