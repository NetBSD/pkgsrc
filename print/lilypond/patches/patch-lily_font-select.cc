$NetBSD: patch-lily_font-select.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/font-select.cc.orig	2013-06-16 18:56:07.000000000 +0000
+++ lily/font-select.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "dimensions.hh"
 #include "all-font-metrics.hh"
 #include "output-def.hh"
