$NetBSD: patch-hier.c,v 1.1 2012/03/12 21:49:49 joerg Exp $

--- hier.c.orig	2012-03-12 21:06:14.000000000 +0000
+++ hier.c
@@ -7,10 +7,8 @@ void hier()
   d(auto_qmail,"bin",-1,-1,0755);
   d(auto_qmail,"man",-1,-1,0755);
   d(auto_qmail,"man/man1",-1,-1,0755);
-  d(auto_qmail,"man/cat1",-1,-1,0755);
 
   c(auto_qmail,"bin","dot-forward",-1,-1,0755);
 
   c(auto_qmail,"man/man1","dot-forward.1",-1,-1,0644);
-  c(auto_qmail,"man/cat1","dot-forward.0",-1,-1,0644);
 }
