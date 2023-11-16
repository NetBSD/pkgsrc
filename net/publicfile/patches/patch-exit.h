$NetBSD: patch-exit.h,v 1.2 2023/11/16 22:55:37 schmonz Exp $

Add missing includes.

--- exit.h.orig	1999-11-09 07:23:46.000000000 +0000
+++ exit.h
@@ -1,6 +1,7 @@
 #ifndef EXIT_H
 #define EXIT_H
 
-extern void _exit();
+#include <stdlib.h>
+#include <unistd.h>
 
 #endif
