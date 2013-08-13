$NetBSD: patch-src_synce__gtk.c,v 1.1 2013/08/13 10:22:57 joerg Exp $

No config.h created by configure.

--- src/synce_gtk.c.orig	2013-08-12 16:44:45.000000000 +0000
+++ src/synce_gtk.c
@@ -16,10 +16,6 @@
  * along with this program. If not, see <http://www.gnu.org/licenses/>.
  */
 
-#ifdef HAVE_CONFIG_H
-#  include "config.h"
-#endif
-
 #include <glib.h>
 #include <glib/gi18n.h>
 #include <gtk/gtk.h>
