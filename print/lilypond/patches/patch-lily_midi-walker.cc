$NetBSD: patch-lily_midi-walker.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/midi-walker.cc.orig	2013-06-16 19:26:10.000000000 +0000
+++ lily/midi-walker.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "midi-walker.hh"
 
 #include "audio-column.hh"
