$NetBSD: patch-lily_paper-outputter.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/paper-outputter.cc.orig	2013-06-16 18:44:44.000000000 +0000
+++ lily/paper-outputter.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "paper-outputter.hh"
 
 #include <cmath>
