$NetBSD: patch-lily_pango-font-scheme.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/pango-font-scheme.cc.orig	2013-06-16 19:18:02.000000000 +0000
+++ lily/pango-font-scheme.cc
@@ -17,6 +17,8 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
+
 #define PANGO_ENABLE_BACKEND // ugh, why necessary?
 
 #include <pango/pangoft2.h>
