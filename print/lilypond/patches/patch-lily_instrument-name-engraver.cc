$NetBSD: patch-lily_instrument-name-engraver.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/instrument-name-engraver.cc.orig	2013-06-16 18:49:53.000000000 +0000
+++ lily/instrument-name-engraver.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "align-interface.hh"
 #include "axis-group-interface.hh"
 #include "engraver.hh"
