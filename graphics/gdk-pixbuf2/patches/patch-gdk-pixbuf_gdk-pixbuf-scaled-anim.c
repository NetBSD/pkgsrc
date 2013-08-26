$NetBSD: patch-gdk-pixbuf_gdk-pixbuf-scaled-anim.c,v 1.1 2013/08/26 14:38:56 richard Exp $

* include config.h early to avoid redefinition warnings on solaris
*
--- gdk-pixbuf/gdk-pixbuf-scaled-anim.c.orig	2012-07-31 23:45:20.000000000 +0000
+++ gdk-pixbuf/gdk-pixbuf-scaled-anim.c
@@ -21,7 +21,7 @@
  * Boston, MA 02111-1307, USA.
  *
  */
-
+#include "config.h"
 #include <glib.h>
 
 #include "gdk-pixbuf.h"
