$NetBSD: patch-glib_glib_gutf8.c,v 1.1 2013/04/13 11:10:04 obache Exp $

* from glib2.0.cygport 2.32.1-not-win32.patch

--- glib/glib/gutf8.c.orig	2012-10-13 14:35:36.000000000 +0000
+++ glib/glib/gutf8.c
@@ -27,7 +27,7 @@
 #endif
 #include <string.h>
 
-#ifdef G_PLATFORM_WIN32
+#ifdef G_OS_WIN32
 #include <stdio.h>
 #define STRICT
 #include <windows.h>
