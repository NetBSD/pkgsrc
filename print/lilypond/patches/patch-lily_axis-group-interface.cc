$NetBSD: patch-lily_axis-group-interface.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/axis-group-interface.cc.orig	2013-06-16 19:13:48.000000000 +0000
+++ lily/axis-group-interface.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "axis-group-interface.hh"
 
 #include "align-interface.hh"
