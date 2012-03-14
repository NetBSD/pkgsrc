$NetBSD: patch-hier.c,v 1.1 2012/03/14 23:15:16 joerg Exp $

--- hier.c.orig	2012-03-13 17:48:44.000000000 +0000
+++ hier.c
@@ -8,21 +8,15 @@ void hier()
   d(auto_home,"doc",-1,-1,02755);
   d(auto_home,"man",-1,-1,02755);
   d(auto_home,"man/man1",-1,-1,02755);
-  d(auto_home,"man/cat1",-1,-1,02755);
 
   c(auto_home,"doc","MATCHUP",-1,-1,0644);
   c(auto_home,"doc","ACCOUNTING",-1,-1,0644);
 
   c(auto_home,"man/man1","matchup.1",-1,-1,0644);
-  c(auto_home,"man/cat1","matchup.0",-1,-1,0644);
   c(auto_home,"man/man1","xqp.1",-1,-1,0644);
-  c(auto_home,"man/cat1","xqp.0",-1,-1,0644);
   c(auto_home,"man/man1","xsender.1",-1,-1,0644);
-  c(auto_home,"man/cat1","xsender.0",-1,-1,0644);
   c(auto_home,"man/man1","xrecipient.1",-1,-1,0644);
-  c(auto_home,"man/cat1","xrecipient.0",-1,-1,0644);
   c(auto_home,"man/man1","columnt.1",-1,-1,0644);
-  c(auto_home,"man/cat1","columnt.0",-1,-1,0644);
 
   c(auto_home,"bin","matchup",-1,-1,0755);
   c(auto_home,"bin","columnt",-1,-1,0755);
