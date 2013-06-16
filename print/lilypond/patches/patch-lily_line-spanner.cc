$NetBSD: patch-lily_line-spanner.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/line-spanner.cc.orig	2013-06-16 19:07:21.000000000 +0000
+++ lily/line-spanner.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "align-interface.hh"
 #include "axis-group-interface.hh"
 #include "font-interface.hh"
