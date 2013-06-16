$NetBSD: patch-lily_event-chord-iterator.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/event-chord-iterator.cc.orig	2013-06-16 19:25:55.000000000 +0000
+++ lily/event-chord-iterator.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "event-chord-iterator.hh"
 
 #include "context.hh"
