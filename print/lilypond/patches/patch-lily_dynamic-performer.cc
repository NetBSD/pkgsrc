$NetBSD: patch-lily_dynamic-performer.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/dynamic-performer.cc.orig	2013-06-16 18:48:59.000000000 +0000
+++ lily/dynamic-performer.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "performer.hh"
 #include "audio-item.hh"
 #include "stream-event.hh"
