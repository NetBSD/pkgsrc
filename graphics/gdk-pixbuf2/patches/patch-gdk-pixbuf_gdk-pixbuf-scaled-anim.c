$NetBSD: patch-gdk-pixbuf_gdk-pixbuf-scaled-anim.c,v 1.3 2021/09/19 08:06:20 nia Exp $

* include config.h early to avoid redefinition warnings on solaris

--- gdk-pixbuf/gdk-pixbuf-scaled-anim.c.orig	2014-03-06 04:36:45.000000000 +0000
+++ gdk-pixbuf/gdk-pixbuf-scaled-anim.c
@@ -19,7 +19,7 @@
  * License along with this library; if not, see <http://www.gnu.org/licenses/>.
  *
  */
-
+#include "config.h"
 #include <glib.h>
 
 #include "gdk-pixbuf.h"
