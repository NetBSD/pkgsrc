$NetBSD: patch-hier.c,v 1.1 2020/06/30 13:40:54 schmonz Exp $

Support DESTDIR.

--- hier.c.orig	2001-06-30 20:44:50.000000000 +0000
+++ hier.c
@@ -2,9 +2,9 @@
 
 void hier()
 {
-  h(auto_home,-1,-1,02755);
+  h(auto_home,-1,-1,0755);
 
-  d(auto_home,"bin",-1,-1,02755);
+  d(auto_home,"bin",-1,-1,0755);
 
   c(auto_home,"bin","822addr",-1,-1,0755);
   c(auto_home,"bin","822body",-1,-1,0755);
