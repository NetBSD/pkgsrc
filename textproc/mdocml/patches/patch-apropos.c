$NetBSD: patch-apropos.c,v 1.2 2012/12/24 13:40:18 jperkin Exp $

--- apropos.c.orig	2011-10-08 20:07:21.000000000 +0000
+++ apropos.c
@@ -33,7 +33,7 @@
 #include <string.h>
 #include <unistd.h>
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__sun)
 # include <db_185.h>
 #else
 # include <db.h>
