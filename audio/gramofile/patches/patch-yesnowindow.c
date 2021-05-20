$NetBSD: patch-yesnowindow.c,v 1.1 2021/05/20 19:24:15 nia Exp $

include missing header for strlen().

--- yesnowindow.c.orig	2000-03-28 21:07:26.000000000 +0000
+++ yesnowindow.c
@@ -16,6 +16,7 @@
 #else
 #include <curses.h>
 #endif
+#include <string.h>
 
 
 int
