$NetBSD: patch-src_npplayer.cpp,v 1.1 2021/08/31 12:06:22 markd Exp $

fix build against glib 2.68.3

--- src/npplayer.cpp.orig	2016-09-24 15:29:58.000000000 +0000
+++ src/npplayer.cpp
@@ -21,6 +21,7 @@
 http://devedge-temp.mozilla.org/library/manuals/2002/plugin/1.0/
 http://dbus.freedesktop.org/doc/dbus/libdbus-tutorial.html
 */
+#include <glib.h>
 extern "C" {
 #include <unistd.h>
 #include <string.h>
@@ -32,7 +33,6 @@ extern "C" {
 #include <fcntl.h>
 
 #include <glib/gprintf.h>
-#include <glib.h>
 #include <gdk/gdkx.h>
 #include <gtk/gtk.h>
 
