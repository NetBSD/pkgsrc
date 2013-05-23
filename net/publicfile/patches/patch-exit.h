$NetBSD: patch-exit.h,v 1.1 2013/05/23 14:57:32 joerg Exp $

--- exit.h.orig	1999-11-09 07:23:46.000000000 +0000
+++ exit.h
@@ -1,6 +1,7 @@
 #ifndef EXIT_H
 #define EXIT_H
 
-extern void _exit();
+#include <stdlib.h>
+#include <unistd.h>
 
 #endif
