$NetBSD: patch-libgnomecups_gnome-cups-queue.h,v 1.1 2014/06/13 22:10:24 schnoebe Exp $

--- libgnomecups/gnome-cups-queue.h.orig	2007-01-02 00:18:51.000000000 +0000
+++ libgnomecups/gnome-cups-queue.h
@@ -3,6 +3,10 @@
 
 #include <glib.h>
 #include <glib-object.h>
+/* transitional, until modified to use the ipp_attribute_t accessors */
+#ifndef _IPP_PRIVATE_STRUCTURES
+# define _IPP_PRIVATE_STRUCTURES 1
+#endif
 #include <cups/ipp.h>
 
 G_BEGIN_DECLS
