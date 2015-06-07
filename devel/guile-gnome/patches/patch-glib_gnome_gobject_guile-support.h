$NetBSD: patch-glib_gnome_gobject_guile-support.h,v 1.1 2015/06/07 12:02:22 gdt Exp $

Modern glib objects to direct inclusion of any sub-headers.
This patch was sent upstream on 20150607.

--- glib/gnome/gobject/guile-support.h.orig	2012-05-07 15:29:35.000000000 +0000
+++ glib/gnome/gobject/guile-support.h
@@ -24,7 +24,7 @@
 #ifndef __GUILE_SUPPORT_H__
 #define __GUILE_SUPPORT_H__
 
-#include <glib/gmacros.h>
+#include <glib.h>
 
 #include <libguile.h>
 
