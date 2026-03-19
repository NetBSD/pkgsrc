$NetBSD: patch-readwrite.h,v 1.1 2026/03/19 07:50:46 nia Exp $

Fix implicit function declarations.

--- readwrite.h.orig	2000-02-29 04:10:12.000000000 +0000
+++ readwrite.h
@@ -1,7 +1,6 @@
 #ifndef READWRITE_H
 #define READWRITE_H
 
-extern int read();
-extern int write();
+#include <unistd.h>
 
 #endif
