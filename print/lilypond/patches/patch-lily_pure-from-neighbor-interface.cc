$NetBSD: patch-lily_pure-from-neighbor-interface.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/pure-from-neighbor-interface.cc.orig	2013-06-16 19:22:25.000000000 +0000
+++ lily/pure-from-neighbor-interface.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "axis-group-interface.hh"
 #include "grob.hh"
 #include "grob-array.hh"
