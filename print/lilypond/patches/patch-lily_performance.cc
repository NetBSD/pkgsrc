$NetBSD: patch-lily_performance.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/performance.cc.orig	2013-06-16 19:28:18.000000000 +0000
+++ lily/performance.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "performance.hh"
 
 #include <ctime>
@@ -56,7 +57,7 @@ Performance::output (Midi_stream &midi_s
   for (vsize i = 0; i < audio_staffs_.size (); i++)
     {
       Audio_staff *s = audio_staffs_[i];
-      debug_output ("[" + to_string (i), true);
+      debug_output ("[" + ::to_string (i), true);
       s->output (midi_stream, i, ports_);
       debug_output ("]", false);
     }
