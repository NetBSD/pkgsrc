$NetBSD: patch-lily_midi-stream.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/midi-stream.cc.orig	2013-06-16 19:28:17.000000000 +0000
+++ lily/midi-stream.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "midi-stream.hh"
 
 #include <cerrno>
