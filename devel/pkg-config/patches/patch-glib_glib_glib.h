$NetBSD: patch-glib_glib_glib.h,v 1.1 2013/04/13 11:10:04 obache Exp $

* from glib2.0.cygport 2.32.1-not-win32.patch

--- glib/glib/glib.h.orig	2012-10-02 05:49:07.000000000 +0000
+++ glib/glib/glib.h
@@ -95,7 +95,7 @@
 #include <glib/gvariant.h>
 #include <glib/gversion.h>
 #include <glib/gversionmacros.h>
-#ifdef G_PLATFORM_WIN32
+#ifdef G_OS_WIN32
 #include <glib/gwin32.h>
 #endif
 
