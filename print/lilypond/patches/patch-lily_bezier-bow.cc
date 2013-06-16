$NetBSD: patch-lily_bezier-bow.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/bezier-bow.cc.orig	2013-06-16 18:45:49.000000000 +0000
+++ lily/bezier-bow.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "misc.hh"
 #include "bezier.hh"
 
