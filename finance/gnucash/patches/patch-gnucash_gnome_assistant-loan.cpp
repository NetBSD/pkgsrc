$NetBSD: patch-gnucash_gnome_assistant-loan.cpp,v 1.1 2021/04/01 08:22:36 wiz Exp $

Fix build with glib 2.68
https://bugs.gnucash.org/show_bug.cgi?id=798156

--- gnucash/gnome/assistant-loan.cpp.orig	2021-03-26 23:08:11.000000000 +0000
+++ gnucash/gnome/assistant-loan.cpp
@@ -23,6 +23,10 @@
  * Boston, MA  02110-1301,  USA       gnu@gnu.org                   *
 \********************************************************************/
 
+#include <glib.h>
+#include <glib/gi18n.h>
+#include <gtk/gtk.h>
+
 extern "C"
 {
 #include <config.h>
@@ -50,9 +54,6 @@ extern "C"
 #endif
 }
 
-#include <glib.h>
-#include <glib/gi18n.h>
-#include <gtk/gtk.h>
 #include <gnc-locale-utils.hpp>
 #include <boost/locale.hpp>
 #include <string>
