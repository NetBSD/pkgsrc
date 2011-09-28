$NetBSD: patch-hier.c,v 1.1 2011/09/28 06:36:58 joerg Exp $

--- hier.c.orig	2011-09-26 08:54:57.000000000 +0000
+++ hier.c
@@ -162,8 +162,6 @@ void hier()
   c(auto_qmail,"man/cat5","qmail-log.0",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/man5","qmail-users.5",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/cat5","qmail-users.0",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/man5","tcp-environ.5",auto_uido,auto_gidq,0644);
-  c(auto_qmail,"man/cat5","tcp-environ.0",auto_uido,auto_gidq,0644);
 
   c(auto_qmail,"man/man7","forgeries.7",auto_uido,auto_gidq,0644);
   c(auto_qmail,"man/cat7","forgeries.0",auto_uido,auto_gidq,0644);
