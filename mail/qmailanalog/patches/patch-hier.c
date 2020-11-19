$NetBSD: patch-hier.c,v 1.3 2020/11/19 09:08:06 schmonz Exp $

Follow hier(7).
Don't install catpages.

--- hier.c.orig	1998-08-30 21:39:27.000000000 +0000
+++ hier.c
@@ -5,24 +5,18 @@ void hier()
   h(auto_home,-1,-1,02755);
 
   d(auto_home,"bin",-1,-1,02755);
-  d(auto_home,"doc",-1,-1,02755);
+  d(auto_home,"share/doc/qmailanalog",-1,-1,02755);
   d(auto_home,"man",-1,-1,02755);
   d(auto_home,"man/man1",-1,-1,02755);
-  d(auto_home,"man/cat1",-1,-1,02755);
 
-  c(auto_home,"doc","MATCHUP",-1,-1,0644);
-  c(auto_home,"doc","ACCOUNTING",-1,-1,0644);
+  c(auto_home,"share/doc/qmailanalog","MATCHUP",-1,-1,0644);
+  c(auto_home,"share/doc/qmailanalog","ACCOUNTING",-1,-1,0644);
 
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
