$NetBSD: patch-diff_system.h,v 1.1 2025/04/29 09:10:51 tnn Exp $

* replace K&R prototypes

--- diff/system.h.orig	2025-04-29 08:58:50.538410570 +0000
+++ diff/system.h
@@ -177,7 +177,7 @@ VOID *malloc ();
 VOID *realloc ();
 #endif
 #ifndef getenv
-char *getenv ();
+char *getenv (const char *);
 #endif
 
 #include <limits.h>
