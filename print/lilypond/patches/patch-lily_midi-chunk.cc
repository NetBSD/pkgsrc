$NetBSD: patch-lily_midi-chunk.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/midi-chunk.cc.orig	2013-06-16 19:28:17.000000000 +0000
+++ lily/midi-chunk.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "midi-chunk.hh"
 
 #include "midi-item.hh"
