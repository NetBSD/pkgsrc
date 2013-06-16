$NetBSD: patch-lily_page-layout-problem.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/page-layout-problem.cc.orig	2013-06-16 18:52:33.000000000 +0000
+++ lily/page-layout-problem.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "page-layout-problem.hh"
 
 #include "align-interface.hh"
