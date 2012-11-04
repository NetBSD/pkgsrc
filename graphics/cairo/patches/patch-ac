$NetBSD: patch-ac,v 1.18 2012/11/04 23:48:54 wiz Exp $

File is only installed by cairo-gobject, so manually
define existence macro.

--- util/cairo-gobject/cairo-gobject.h.orig	2010-09-09 15:56:24.000000000 +0000
+++ util/cairo-gobject/cairo-gobject.h
@@ -39,6 +39,9 @@
 
 #include <cairo.h>
 
+/* if this header is installed, cairo has gobject functions */
+#define CAIRO_HAS_GOBJECT_FUNCTIONS 1
+
 #if CAIRO_HAS_GOBJECT_FUNCTIONS
 
 #include <glib-object.h>
