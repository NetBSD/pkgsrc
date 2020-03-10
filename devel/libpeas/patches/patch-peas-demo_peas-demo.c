$NetBSD: patch-peas-demo_peas-demo.c,v 1.1 2020/03/10 22:30:30 wiz Exp $

Add header for setlocale().
https://gitlab.gnome.org/GNOME/libpeas/issues/39

--- peas-demo/peas-demo.c.orig	2020-03-06 21:12:16.247286600 +0000
+++ peas-demo/peas-demo.c
@@ -30,6 +30,8 @@
 #include <libpeas/peas.h>
 #include <libpeas-gtk/peas-gtk.h>
 
+#include <locale.h>
+
 #include "peas-demo-window.h"
 
 gboolean run_from_build_dir;
