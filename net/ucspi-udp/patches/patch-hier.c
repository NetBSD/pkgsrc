$NetBSD: patch-hier.c,v 1.1 2021/11/15 10:08:17 schmonz Exp $

Avoid conflicts by not installing recordio.

--- hier.c.orig	2016-03-29 19:44:38.000000000 +0000
+++ hier.c
@@ -8,7 +8,6 @@ void hier()
   c(auto_home,"bin","udplisten",-1,-1,0755);
   c(auto_home,"bin","udprules",-1,-1,0755);
   c(auto_home,"bin","udprulescheck",-1,-1,0755);
-  c(auto_home,"bin","recordio",-1,-1,0755);
   c(auto_home,"bin","udpconnect",-1,-1,0755);
   c(auto_home,"bin","udpcat",-1,-1,0755);
 }
