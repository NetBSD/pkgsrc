$NetBSD: patch-lily_event-iterator.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/event-iterator.cc.orig	2013-06-16 19:11:41.000000000 +0000
+++ lily/event-iterator.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "event-iterator.hh"
 
 #include "context.hh"
