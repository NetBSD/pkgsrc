$NetBSD: patch-lily_music-wrapper-iterator.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/music-wrapper-iterator.cc.orig	2013-06-16 19:26:26.000000000 +0000
+++ lily/music-wrapper-iterator.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "music-wrapper-iterator.hh"
 #include "music-wrapper.hh"
 #include "music.hh"
