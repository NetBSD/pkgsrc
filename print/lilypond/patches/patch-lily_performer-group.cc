$NetBSD: patch-lily_performer-group.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/performer-group.cc.orig	2013-06-16 18:53:39.000000000 +0000
+++ lily/performer-group.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "performer-group.hh"
 
 #include "context.hh"
