$NetBSD: patch-compface.h,v 1.1 2024/08/05 07:52:00 tnn Exp $

Add missing includes for strcat(3) and read(2)

--- compface.h.orig	2024-07-03 08:34:49.566707612 +0000
+++ compface.h
@@ -17,6 +17,8 @@
 #define COMPFACE_H
 
 #include <setjmp.h>
+#include <string.h>
+#include <unistd.h>
 
 /* For all function declarations, if ANSI then use a prototype. */
 
