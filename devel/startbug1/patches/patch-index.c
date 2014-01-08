$NetBSD: patch-index.c,v 1.1 2014/01/08 14:59:15 ryoon Exp $

* * Follow pkgsrc www/cgic manner

--- index.c.orig	2012-11-28 06:40:22.000000000 +0000
+++ index.c
@@ -8,7 +8,8 @@
 #include "db_top.h"
 
 /* index.cgi */
-int cgiMain() {
+int main() {
+    cgiInit();
     double start = get_microseconds();
     ActionType type = analysis_action();
     int ret = 0;
