$NetBSD: patch-lessons.h,v 1.1 2026/08/30 09:14:25 he Exp $

Sprinkle "const" to deal with string constants and get rid of warnings.

--- lessons.h.orig	2026-08-30 09:09:56.970093490 +0000
+++ lessons.h
@@ -22,6 +22,6 @@
 #ifndef LESSONS_H
 #define LESSONS_H
 
-extern char *lessons[];
+extern const char *lessons[];
 
 #endif
