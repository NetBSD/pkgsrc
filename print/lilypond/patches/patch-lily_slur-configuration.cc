$NetBSD: patch-lily_slur-configuration.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/slur-configuration.cc.orig	2013-06-16 19:28:18.000000000 +0000
+++ lily/slur-configuration.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "slur-configuration.hh"
 
 #include "item.hh"
