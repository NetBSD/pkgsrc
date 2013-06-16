$NetBSD: patch-lily_span-bar-stub-engraver.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/span-bar-stub-engraver.cc.orig	2013-06-16 19:21:44.000000000 +0000
+++ lily/span-bar-stub-engraver.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include <algorithm>
 
 #include "align-interface.hh"
