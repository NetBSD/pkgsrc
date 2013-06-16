$NetBSD: patch-lily_slur.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/slur.cc.orig	2013-06-16 18:48:41.000000000 +0000
+++ lily/slur.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "slur.hh"
 #include "grob-info.hh"
 #include "grob-array.hh"
