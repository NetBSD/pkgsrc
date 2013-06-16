$NetBSD: patch-lily_change-iterator.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/change-iterator.cc.orig	2013-06-16 19:11:14.000000000 +0000
+++ lily/change-iterator.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "change-iterator.hh"
 
 #include "context.hh"
