$NetBSD: patch-hier.c,v 1.2 2017/01/02 03:48:11 schmonz Exp $

Install docs following hier(7), and don't install catpages.

--- hier.c.orig	1998-05-19 10:15:50.000000000 +0000
+++ hier.c
@@ -5,12 +5,10 @@ void hier()
   h(auto_qmail,-1,-1,0755);
 
   d(auto_qmail,"bin",-1,-1,0755);
-  d(auto_qmail,"man",-1,-1,0755);
-  d(auto_qmail,"man/man1",-1,-1,0755);
-  d(auto_qmail,"man/cat1",-1,-1,0755);
+  d(auto_qmail,"@PKGMANDIR@",-1,-1,0755);
+  d(auto_qmail,"@PKGMANDIR@/man1",-1,-1,0755);
 
   c(auto_qmail,"bin","dot-forward",-1,-1,0755);
 
-  c(auto_qmail,"man/man1","dot-forward.1",-1,-1,0644);
-  c(auto_qmail,"man/cat1","dot-forward.0",-1,-1,0644);
+  c(auto_qmail,"@PKGMANDIR@/man1","dot-forward.1",-1,-1,0644);
 }
