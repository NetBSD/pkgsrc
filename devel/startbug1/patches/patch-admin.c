$NetBSD: patch-admin.c,v 1.1 2014/01/08 14:59:15 ryoon Exp $

* Follow pkgsrc www/cgic manner

--- admin.c.orig	2012-11-28 06:40:22.000000000 +0000
+++ admin.c
@@ -7,7 +7,8 @@
 #include "db_top.h"
 
 /* management main */
-int cgiMain() {
+int main() {
+    cgiInit();
     ActionType type = analysis_action();
     int ret = 0;
 
