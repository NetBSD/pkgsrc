$NetBSD: patch-Source_Checks_Curses_CheckCurses.c,v 1.1 2018/07/24 12:14:38 ryoon Exp $

--- Source/Checks/Curses/CheckCurses.c.orig	2018-07-17 11:29:00.000000000 +0000
+++ Source/Checks/Curses/CheckCurses.c
@@ -10,6 +10,6 @@
 
 int main()
 {
-  curses_version();
+  flash();
   return 0;
 }
