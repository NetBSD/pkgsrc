$NetBSD: patch-lily_simple-music-iterator.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/simple-music-iterator.cc.orig	2013-06-16 19:07:39.000000000 +0000
+++ lily/simple-music-iterator.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "simple-music-iterator.hh"
 
 #include "music.hh"
