$NetBSD: patch-catman.c,v 1.1 2013/10/11 14:45:18 wiz Exp $

SunOS fix.

--- catman.c.orig	2013-10-05 14:09:07.000000000 +0000
+++ catman.c
@@ -31,7 +31,7 @@
 #include <string.h>
 #include <unistd.h>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__sun)
 # include <db_185.h>
 #else
 # include <db.h>
