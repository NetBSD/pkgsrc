$NetBSD: patch-lily_auto-beam-engraver.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/auto-beam-engraver.cc.orig	2013-06-16 19:20:34.000000000 +0000
+++ lily/auto-beam-engraver.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "beaming-pattern.hh"
 #include "beam.hh"
 #include "context.hh"
