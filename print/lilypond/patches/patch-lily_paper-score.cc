$NetBSD: patch-lily_paper-score.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/paper-score.cc.orig	2013-06-16 18:58:54.000000000 +0000
+++ lily/paper-score.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "paper-score.hh"
 
 #include "all-font-metrics.hh"
