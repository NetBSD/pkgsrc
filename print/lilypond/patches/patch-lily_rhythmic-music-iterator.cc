$NetBSD: patch-lily_rhythmic-music-iterator.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/rhythmic-music-iterator.cc.orig	2013-06-16 18:51:27.000000000 +0000
+++ lily/rhythmic-music-iterator.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "rhythmic-music-iterator.hh"
 
 #include "context.hh"
