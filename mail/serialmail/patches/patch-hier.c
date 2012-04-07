$NetBSD: patch-hier.c,v 1.1 2012/04/07 13:17:11 joerg Exp $

--- hier.c.orig	2012-04-07 11:39:37.000000000 +0000
+++ hier.c
@@ -9,7 +9,6 @@ void hier()
   d(auto_home,"share/doc/serialmail",-1,-1,0755);
   d(auto_home,"man",-1,-1,0755);
   d(auto_home,"man/man1",-1,-1,0755);
-  d(auto_home,"man/cat1",-1,-1,0755);
 
   c(auto_home,"bin","serialqmtp",-1,-1,0755);
   c(auto_home,"bin","serialsmtp",-1,-1,0755);
@@ -18,15 +17,10 @@ void hier()
   c(auto_home,"bin","maildirserial",-1,-1,0755);
 
   c(auto_home,"man/man1","serialqmtp.1",-1,-1,0644);
-  c(auto_home,"man/cat1","serialqmtp.0",-1,-1,0644);
   c(auto_home,"man/man1","serialsmtp.1",-1,-1,0644);
-  c(auto_home,"man/cat1","serialsmtp.0",-1,-1,0644);
   c(auto_home,"man/man1","maildirqmtp.1",-1,-1,0644);
-  c(auto_home,"man/cat1","maildirqmtp.0",-1,-1,0644);
   c(auto_home,"man/man1","maildirsmtp.1",-1,-1,0644);
-  c(auto_home,"man/cat1","maildirsmtp.0",-1,-1,0644);
   c(auto_home,"man/man1","maildirserial.1",-1,-1,0644);
-  c(auto_home,"man/cat1","maildirserial.0",-1,-1,0644);
 
   c(auto_home,"share/doc/serialmail","FROMISP",-1,-1,0644);
   c(auto_home,"share/doc/serialmail","TOISP",-1,-1,0644);
