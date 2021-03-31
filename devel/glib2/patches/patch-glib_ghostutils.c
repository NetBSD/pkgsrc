$NetBSD: patch-glib_ghostutils.c,v 1.2 2021/03/31 10:11:38 wiz Exp $

Include glibconfig.h to get the G_OS_UNIX token
https://gitlab.gnome.org/GNOME/glib/-/commit/1fafbb82b0049dc76a72ebaeccda46db7166e7f2

--- glib/ghostutils.c.orig	2021-03-18 13:28:31.903625000 +0000
+++ glib/ghostutils.c
@@ -18,6 +18,7 @@
  */
 
 #include "config.h"
+#include "glibconfig.h"
 
 #include <string.h>
 
