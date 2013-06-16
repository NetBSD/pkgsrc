$NetBSD: patch-lily_tie-configuration.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/tie-configuration.cc.orig	2013-06-16 18:59:33.000000000 +0000
+++ lily/tie-configuration.cc
@@ -18,6 +18,7 @@
   along with LilyPond.  If not, see <http://www.gnu.org/licenses/>.
 */
 
+#include "config.hh"
 #include "tie-configuration.hh"
 
 #include "warn.hh"
