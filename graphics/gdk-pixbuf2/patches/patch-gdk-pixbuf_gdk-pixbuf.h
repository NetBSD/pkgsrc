$NetBSD: patch-gdk-pixbuf_gdk-pixbuf.h,v 1.1 2013/08/26 14:38:56 richard Exp $

* include config.h early to avoid redefinition warnings on solaris
* 
--- gdk-pixbuf/gdk-pixbuf.h.orig	2011-08-16 01:45:14.000000000 +0000
+++ gdk-pixbuf/gdk-pixbuf.h
@@ -27,7 +27,7 @@
 #define GDK_PIXBUF_H
 
 #define GDK_PIXBUF_H_INSIDE
-
+#include "config.h"
 #include <glib.h>
 #include <gdk-pixbuf/gdk-pixbuf-features.h>
 #include <glib-object.h>
