$NetBSD: patch-testsync.c,v 1.1 2018/11/12 17:54:40 schmonz Exp $

Libtoolize.

--- testsync.c.orig	1998-07-13 19:43:05.000000000 +0000
+++ testsync.c
@@ -2,7 +2,7 @@
 #include <fcntl.h>
 #include <string.h>
 
-inline void msg(const char* m)
+void msg(const char* m)
 {
   write(1, m, strlen(m));
 }
