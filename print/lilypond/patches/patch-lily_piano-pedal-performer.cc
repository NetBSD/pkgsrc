$NetBSD: patch-lily_piano-pedal-performer.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/piano-pedal-performer.cc.orig	2013-06-16 18:48:08.000000000 +0000
+++ lily/piano-pedal-performer.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "performer.hh"
 
 #include "audio-item.hh"
