$NetBSD: patch-lily_dynamic-engraver.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/dynamic-engraver.cc.orig	2013-06-16 19:18:47.000000000 +0000
+++ lily/dynamic-engraver.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "axis-group-interface.hh"
 #include "context.hh"
 #include "engraver.hh"
