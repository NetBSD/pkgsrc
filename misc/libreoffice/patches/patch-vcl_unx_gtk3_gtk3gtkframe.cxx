$NetBSD: patch-vcl_unx_gtk3_gtk3gtkframe.cxx,v 1.1 2017/12/24 09:13:10 ryoon Exp $

* Fix build with gtk3

--- vcl/unx/gtk3/gtk3gtkframe.cxx.orig	2017-12-12 17:45:07.000000000 +0000
+++ vcl/unx/gtk3/gtk3gtkframe.cxx
@@ -21,6 +21,7 @@
 #include <unx/gtk/gtkdata.hxx>
 #include <unx/gtk/gtkinst.hxx>
 #include <unx/gtk/gtkgdi.hxx>
+#include <unx/gtk/gtksalmenu.hxx>
 #include <vcl/help.hxx>
 #include <vcl/keycodes.hxx>
 #include <vcl/layout.hxx>
