$NetBSD: patch-lily_pango-select.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/pango-select.cc.orig	2013-06-16 19:28:18.000000000 +0000
+++ lily/pango-select.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "dimensions.hh"
 #include "all-font-metrics.hh"
 #include "output-def.hh"
