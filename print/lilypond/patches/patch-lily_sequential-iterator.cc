$NetBSD: patch-lily_sequential-iterator.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/sequential-iterator.cc.orig	2013-06-16 18:49:30.000000000 +0000
+++ lily/sequential-iterator.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "sequential-iterator.hh"
 #include "music.hh"
 #include "translator-group.hh"
