$NetBSD: patch-src_synce__plugin.c,v 1.1 2013/08/13 10:22:57 joerg Exp $

No config.h created by configure.

--- src/synce_plugin.c.orig	2013-08-12 16:44:49.000000000 +0000
+++ src/synce_plugin.c
@@ -16,9 +16,6 @@
  * along with this program. If not, see <http://www.gnu.org/licenses/>.
  */
 
-#ifdef HAVE_CONFIG_H
-#  include "config.h"
-#endif
 #include "pluginconfig.h"
 
 #include "common/version.h"
