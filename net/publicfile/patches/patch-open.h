$NetBSD: patch-open.h,v 1.2 2023/11/16 22:55:37 schmonz Exp $

Specify expected parameters.

--- open.h.orig	1999-11-09 07:23:46.000000000 +0000
+++ open.h
@@ -1,10 +1,7 @@
 #ifndef OPEN_H
 #define OPEN_H
 
-extern int open_read();
-extern int open_excl();
-extern int open_append();
-extern int open_trunc();
-extern int open_write();
+extern int open_read(char *);
+extern int open_trunc(char *);
 
 #endif
