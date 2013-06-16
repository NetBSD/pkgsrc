$NetBSD: patch-lily_all-font-metrics-scheme.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/all-font-metrics-scheme.cc.orig	2013-06-16 19:19:52.000000000 +0000
+++ lily/all-font-metrics-scheme.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "all-font-metrics.hh"
 #include "main.hh"
 
