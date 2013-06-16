$NetBSD: patch-lily_main.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/main.cc.orig	2013-06-16 19:28:17.000000000 +0000
+++ lily/main.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "main.hh"
 
 #include <cassert>
