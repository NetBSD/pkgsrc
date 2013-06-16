$NetBSD: patch-lily_bezier.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/bezier.cc.orig	2013-06-16 19:02:18.000000000 +0000
+++ lily/bezier.cc
@@ -17,6 +17,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "bezier.hh"
 #include "warn.hh"
 #include "libc-extension.hh"
