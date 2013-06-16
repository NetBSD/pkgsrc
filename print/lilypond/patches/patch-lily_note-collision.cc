$NetBSD: patch-lily_note-collision.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/note-collision.cc.orig	2013-06-16 19:10:25.000000000 +0000
+++ lily/note-collision.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "note-collision.hh"
 
 #include "axis-group-interface.hh"
