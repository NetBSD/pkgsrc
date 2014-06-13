$NetBSD: patch-libgnomecups_gnome-cups-request.h,v 1.1 2014/06/13 22:10:24 schnoebe Exp $

--- libgnomecups/gnome-cups-request.h.orig	2007-01-02 00:18:51.000000000 +0000
+++ libgnomecups/gnome-cups-request.h
@@ -1,6 +1,10 @@
 #ifndef GNOME_CUPS_REQUEST_H
 #define GNOME_CUPS_REQUEST_H
 
+/* transitional, until modified to use the ipp_attribute_t accessors */
+#ifndef _IPP_PRIVATE_STRUCTURES
+# define _IPP_PRIVATE_STRUCTURES 1
+#endif
 #include <cups/ipp.h>
 #include <glib.h>
 #include "gnome-cups-init.h"
