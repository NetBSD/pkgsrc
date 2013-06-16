$NetBSD: patch-lily_chord-tremolo-iterator.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/chord-tremolo-iterator.cc.orig	2013-06-16 19:27:35.000000000 +0000
+++ lily/chord-tremolo-iterator.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "chord-tremolo-iterator.hh"
 
 #include "input.hh"
