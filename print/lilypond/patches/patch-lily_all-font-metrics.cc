$NetBSD: patch-lily_all-font-metrics.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/all-font-metrics.cc.orig	2013-06-16 19:12:28.000000000 +0000
+++ lily/all-font-metrics.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "all-font-metrics.hh"
 
 #include "string-convert.hh"
