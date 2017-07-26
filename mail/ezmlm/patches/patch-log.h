$NetBSD: patch-log.h,v 1.2 2017/07/26 02:02:23 schmonz Exp $

Add some prototypes, missing headers and redefine log() to not conflict
with libm.

--- log.h.orig	2013-02-25 16:47:13.000000000 +0000
+++ log.h
@@ -1,6 +1,7 @@
 #ifndef LOG_H
 #define LOG_H
 
-extern void log();
+#define log(x,y) my_log(x,y)
+extern void log(char *, char *);
 
 #endif
